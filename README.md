<p align="center">
  <img src="assets/BattleShip.svg" alt="BattleShip NX" width="640">
</p>

# BattleShip NX (Nintendo Switch Port)

> [!WARNING]  
> **This is a community fork of the [original BattleShip PC port](https://github.com/JRickey/BattleShip) specifically geared towards a Nintendo Switch (NX) release.**  
> Please **DO NOT** open issues on the original BattleShip repository or the Harbour Masters repositories for any bugs, crashes, or issues you encounter while using or building this Switch port. Direct all Switch-related issues to this repository's issue tracker.

**BattleShip NX** brings the original BattleShip project — a native port of **Super Smash Bros. (N64)** — to the **Nintendo Switch**. It leverages the [VetriTheRetri/ssb-decomp-re](https://github.com/vetritheretri/ssb-decomp-re) decompilation, using [libultraship](https://github.com/Kenix3/libultraship) for console-native rendering, audio, and input.

Runs natively on **Nintendo Switch** via Homebrew (libnx).

---

## No Copyrighted Assets Included

**None of Nintendo's assets (code, textures, audio, models, text, ROM data) are checked into this repo or distributed with builds.** The port is a pure C/C++ source tree; every byte of Nintendo-owned data must be extracted at build time from a ROM that *you* supply. If you do not own a legal copy of Super Smash Bros. for the Nintendo 64, you cannot build or run this project.

## Features

### Nintendo Switch Optimizations
- **Console-Native Rendering**: OpenGL backend fully tuned for the Nintendo Switch.
- **Widescreen Support**: Full 16:9 widescreen gameplay, perfectly fitting the Switch screen and docked mode.
- **High-Resolution Textures**: Supports reading hi-res texture packs straight out of a `.zip` on your SD card.

### Switch Controls
- **Plug-and-Play Multiplayer**: Local multiplayer for up to 4 players out of the box.
- **Hardware Support**: Full support for Nintendo Switch Pro Controllers, Joy-Cons (paired and single), and GameCube Controllers via the official USB adapter.
- **Custom Mapping**: Per-controller configuration UI available via the in-game menu.

### Gameplay Enhancements
- **Classic Co-op**: Play the originally single-player Classic mode with 2-player local co-op.
- **Competitive Ruleset**: One-click tournament rules, neutral spawns, and disabled stage hazards.
- **Input Tweaks**: Disable tap jump, C-Stick smash, D-Pad to jump, and customizable analog stick ranges.
- **Hitbox View**: Visualize hitboxes, hurtboxes, and collision data.

---

## Building and Installation

For instructions on how to set up your `devkitA64` environment and compile the `.nro` file, please consult the [building instructions](BUILDING.md).

### SD Card Deployment
Once compiled, you must place `BattleShip.nro` in your Switch's `switch/` directory along with its required assets. Because the Switch cannot run the asset extractor natively, you must run the game on Desktop first to generate `BattleShip.o2r`.

Your SD card folder should look like this:
```
sdmc:/switch/BattleShipNX/
├── BattleShip.nro
├── BattleShip.o2r         (Extracted ROM assets)
├── f3d.o2r                (Packaged Fast3D shaders)
├── gamecontrollerdb.txt   (Controller mappings)
├── assets/                (Custom UI fonts)
└── yamls/                 (Configuration and ROM offsets)
```

---

## Credits & Licensing

- **Original BattleShip PC Port**: Massive thanks to [JRickey](https://github.com/JRickey) for creating the original BattleShip project that this Switch port is based upon.
- **Decompilation**: [VetriTheRetri/ssb-decomp-re](https://github.com/VetriTheRetri/ssb-decomp-re) and its contributors.
- **Runtime Framework**: [libultraship](https://github.com/Kenix3/libultraship) (originated by the Harbour Masters team).
- **Asset Pipeline**: [Torch](https://github.com/HarbourMasters/Torch) (originated by the Harbour Masters team).
- Game code, data, sound, textures, models, and trademarks: **© Nintendo / HAL Laboratory.** Not included in this repository, not redistributed, and not endorsed by them.

This project is **not affiliated with, endorsed by, or authorized by Nintendo.** It is a personal, non-commercial research and preservation effort. Do not upload ROMs, extracted `.o2r` archives, or any other Nintendo-owned data to issues or pull requests.

This project is **not affiliated with, endorsed by, or authorized by JRickey** (the creator of the original PC port). Issues, bugs, and support questions about this Nintendo Switch port should **not** be directed to JRickey or the original repo.

This project is **not affiliated with, endorsed by, or authorized by Harbour Masters** either. It uses libultraship and Torch as upstream dependencies via personal forks, but it is an independent fan effort. Issues, bugs, and support questions about this port should not be directed to the Harbour Masters team.
