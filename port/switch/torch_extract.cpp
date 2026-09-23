#include "torch_extract.h"

#include "Companion.h"

#include "spdlog/sinks/basic_file_sink.h"
#include "spdlog/spdlog.h"

#include <exception>
#include <filesystem>
#include <memory>

namespace ssb64 {

namespace {

/* Route Torch's spdlog output (notably the "ROM not recognized. Got SHA-1"
 * diagnostics) to the extraction log, then put libultraship's logger back.
 * Loggers are kept alive in statics: SPDLOG_* macros on other threads hold a
 * raw pointer to whichever default logger was current when they fired. */
class ScopedTorchLogger {
  public:
    explicit ScopedTorchLogger(const std::string& logPath) : mPrevious(spdlog::default_logger()) {
        if (logPath.empty()) {
            return;
        }
        try {
            static std::shared_ptr<spdlog::logger> sTorchLogger;
            auto sink = std::make_shared<spdlog::sinks::basic_file_sink_mt>(logPath, /*truncate=*/false);
            sTorchLogger = std::make_shared<spdlog::logger>("torch", sink);
            sTorchLogger->set_level(spdlog::level::info);
            sTorchLogger->flush_on(spdlog::level::info);
            spdlog::set_default_logger(sTorchLogger);
            mSwapped = true;
        } catch (const std::exception&) {
            // Log file unwritable: Torch keeps logging through the game's logger.
        }
    }
    ~ScopedTorchLogger() {
        if (mSwapped) {
            spdlog::set_default_logger(mPrevious);
        }
    }

  private:
    std::shared_ptr<spdlog::logger> mPrevious;
    bool mSwapped = false;
};

/* libstdc++ treats "sdmc:" as a plain relative path component, so the
 * canonicalizing calls Torch makes (fs::relative -> weakly_canonical) would
 * resolve "sdmc:/switch/..." against the current directory and fail. Rooted
 * paths without the device name resolve to the default device (the SD card)
 * in newlib, and canonicalize cleanly. */
std::string StripSdmcPrefix(const std::string& path) {
    constexpr const char kPrefix[] = "sdmc:";
    constexpr size_t kLen = sizeof(kPrefix) - 1;
    if (path.compare(0, kLen, kPrefix) == 0 && path.size() > kLen && path[kLen] == '/') {
        return path.substr(kLen);
    }
    return path;
}

} // namespace

bool TorchExtractO2R(const std::string& romPath, const std::string& srcDir, const std::string& dstDir,
                     const std::string& logPath, std::atomic<size_t>& assetCount, std::string& error) {
    ScopedTorchLogger logScope(logPath);

    std::error_code ec;
    if (!std::filesystem::exists(romPath, ec)) {
        error = "ROM not found";
        return false;
    }

    std::string outPath;
    try {
        auto instance = std::make_unique<Companion>(std::filesystem::path(StripSdmcPrefix(romPath)),
                                                    ArchiveType::O2R, /*debug=*/false,
                                                    StripSdmcPrefix(srcDir), StripSdmcPrefix(dstDir));
        Companion::Instance = instance.get();
        instance->Init(ExportType::Binary, assetCount);
        // Process() has log-and-return exits (unrecognized ROM SHA-1, bad
        // config) that throw nothing; it only sets the output path once it
        // gets as far as opening the archive writer.
        outPath = instance->GetOutputPath();
        Companion::Instance = nullptr;
    } catch (const std::exception& e) {
        Companion::Instance = nullptr;
        error = std::string("Extractor error: ") + e.what();
        return false;
    } catch (...) {
        Companion::Instance = nullptr;
        error = "Extractor error";
        return false;
    }

    if (outPath.empty()) {
        error = "ROM not recognized (needs an unmodified dump; SHA-1 is in the log)";
        return false;
    }
    if (!std::filesystem::exists(outPath, ec)) {
        error = "Archive was not written (SD card full?)";
        return false;
    }
    return true;
}

} // namespace ssb64
