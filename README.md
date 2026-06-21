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

When running the game, you MUST be sure that you are running it either from the homebrew menu via holding R when starting a game, through Spharia, or through a forwarder. You probably shouldnt run it in applet mode.

---

## Mods & High-Res Textures

Yes! The Switch port fully supports assets, models, and high-res texture packs just like the PC version.

1. **High-Res Textures**: Simply drop your HD texture pack `.zip` files (or loose PNGs) directly into the `mods/` folder next to your `BattleShip.nro` on the SD card. They are loaded instantly on boot!
2. **Custom Models / Audio / Stages**: Drop any packaged `.o2r` mod files into the `mods/` folder.
3. **C-Mods**: Support for TCC-scripted mods depends on the specific mod's architecture, but most standard asset replacement mods will work flawlessly out of the box.

*Your SD card layout with mods should look like this:*
```
sdmc:/switch/BattleShipNX/
├── BattleShip.nro
├── BattleShip.o2r
├── f3d.o2r
├── mods/
│   ├── hd_textures.zip
│   ├── new_character.o2r
```

---

## Configuration & Debug Menu

All features, enhancements, and control remaps are available via the in-game Configuration/Debug menu.

- **To open the menu:** Press the **Minus (-)** button on your Nintendo Switch controller (or **ESC** if you have a USB keyboard connected).
- Use the touchscreen or the D-Pad to navigate the menus.

## Features

### Nintendo Switch Optimizations
- **Console-Native Rendering**: OpenGL backend fully tuned for the Nintendo Switch.
- **Widescreen Support**: Full 16:9 widescreen gameplay, perfectly fitting the Switch screen and docked mode.
- **High-Resolution Textures**: Supports reading hi-res texture packs straight out of a `.zip` on your SD card.

### Switch Controls
- **Plug-and-Play Multiplayer**: Local multiplayer for up to 4 players out of the box.
- **Hardware Support**: Full support for Nintendo Switch Pro Controllers, Joy-Cons (paired and single), and GameCube Controllers via the official USB adapter.

**Default Mappings (Switch Pro / Joy-Con):**
- **A Button**: Attack (N64 A)
- **B Button**: Special (N64 B)
- **X / Y Buttons**: Unmapped by default
- **L Button**: Taunt (N64 L)
- **ZL**: Shield (N64 Z)
- **ZR**: Grab (N64 R)
- **R Button**: Unmapped by default
- **Right Stick**: Jump / Smash Attacks (N64 C-Buttons)
- **Minus (-)**: Open Configuration Menu
- **Plus (+)**: Pause (N64 Start)
- *Note: Every button and analog stick can be fully remapped via the Configuration Menu.*

### Gameplay Enhancements
- **Classic Co-op**: Play the originally single-player Classic mode with 2-player local co-op.
- **Competitive Ruleset**: One-click tournament rules, neutral spawns, and disabled stage hazards.
- **Input Tweaks**: Disable tap jump, C-Stick smash, D-Pad to jump, and customizable analog stick ranges.
- **Hitbox View**: Visualize hitboxes, hurtboxes, and collision data.

---

## Building and Installation

To compile the `.nro` for your Switch, you must first install [devkitPro](https://devkitpro.org/) and open an MSYS2 terminal. 

You must install the following packages via the MSYS2 `pacman` package manager:
```bash
pacman -S switch-dev switch-sdl2 switch-pkg-config ninja
```

For full, step-by-step instructions on configuring the CMake environment and extracting your ROM, please consult the [building instructions](BUILDING.md).

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
