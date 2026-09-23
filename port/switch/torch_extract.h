#pragma once

#include <atomic>
#include <cstddef>
#include <string>

namespace ssb64 {

/* In-process Torch extraction for the Switch build (the console can't spawn
 * the desktop torch sidecar). Built as its own static library so Torch's
 * headers — which define a global StringHelper that collides with
 * libultraship's — never reach port TUs. Only this header is shared.
 *
 * Writes BattleShip.o2r into `dstDir` from the ROM at `romPath`, using the
 * config.yml + yamls/ staged under `srcDir`. Torch's log output goes to
 * `logPath` for the duration of the call. `assetCount` is bumped as assets
 * are exported, for progress display. Returns true on success; on failure
 * `error` holds a user-facing reason. Not re-entrant (Torch is a singleton). */
bool TorchExtractO2R(const std::string& romPath, const std::string& srcDir, const std::string& dstDir,
                     const std::string& logPath, std::atomic<size_t>& assetCount, std::string& error);

} // namespace ssb64
