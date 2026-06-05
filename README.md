# QidiBox Filament Tag Reader/Writer

> **Fork notice:** This is a community fork of
> [alexk42/qidi-filament-nfc-flipper](https://github.com/alexk42/qidi-filament-nfc-flipper),
> expanded to cover all 35 QIDI material codes. Original work (c) 2025 Alex
> Kilimnik under the MIT License (retained in full). Maintained by @jamespinckney1.
> Unofficial - not affiliated with, endorsed by, or supported by QIDI.

A Flipper Zero application for reading and writing the RFID tags used by the
QidiBox filament management system, so any spool can be auto-recognized by the
QIDI Box just like official QIDI filament.

## Features

- **Read Tags**: Scan an existing QidiBox filament tag to view its material type and color
- **Write Tags**: Program a blank tag with a material type and color
- Support for **all 35 QIDI material types** (full code table from the QIDI wiki)
- Support for all 24 predefined QIDI colors

## Installation

1. Download the latest `qidi_filament_nfc.fap` from the [Releases](https://github.com/alexk42/qidi-filament-nfc-flipper/releases) page
2. Copy the `.fap` file to your Flipper Zero's SD card at `/ext/apps/NFC/`
3. On the Flipper: Apps -> NFC -> QidiBox Filament

## Building from Source

### Quick way (ufbt)

```bash
pip install ufbt          # or: pipx install ufbt
cd qidi-filament-nfc-flipper
ufbt                      # produces dist/qidi_filament_nfc.fap
ufbt launch               # with a Flipper connected: build + install + open
```

### As part of the firmware tree (fbt)

1. Clone into your firmware's `applications_user` directory:
   ```bash
   cd /path/to/flipperzero-firmware/applications_user
   git clone https://github.com/alexk42/qidi-filament-nfc-flipper.git
   ```
2. Build:
   ```bash
   cd /path/to/flipperzero-firmware
   ./fbt fap_qidi_filament_nfc
   ```
3. The compiled `.fap` lands in `build/f7-firmware-D/.extapps/`

## Technical Details

Specifications based on the [QIDI RFID Tag Guide](https://wiki.qidi3d.com/en/QIDIBOX/RFID).

The QIDI wiki lists material and color codes in decimal; the value is written
directly into the tag byte, so e.g. the wiki's "40" for PETG Tough is stored as
`0x28`. This app handles that mapping for every supported code.

- **Tag Type**: MIFARE Classic 1K (FM11RF08S chip on factory tags; generic 1K with default keys for blanks)
- **Frequency**: 13.56 MHz
- **Protocol**: ISO/IEC 14443-A
- **Authentication**: Default MIFARE keys (FF FF FF FF FF FF)
- **Data Location**: Sector 1, Block 0 (absolute block 4)
- **Data Format**: 3 bytes
  - Byte 0: Material code
  - Byte 1: Color code
  - Byte 2: Manufacturer code (set to 1)

## Supported Materials

PLA, PLA Matte, PLA Metal, PLA Silk, PLA-CF, PLA-Wood, PLA Basic,
PLA Matte Basic, ABS, ABS-GF, ABS-Metal, ABS-Odorless, ASA, ASA-AERO, UltraPA,
PA-CF, UltraPA-CF25, PA12-CF, PAHT-CF, PAHT-GF, Support For PAHT,
Support For PET/PA, PC/ABS-FR, PET-CF, PET-GF, PETG Basic, PETG Tough,
PETG Rapido, PETG-CF, PETG-GF, PPS-CF, PETG Translucent, PVA, TPU-Aero, TPU.

## Supported Colors

White, Black, Light Gray, Lime Green, Mint Green, Blue, Pink, Yellow,
Dark Green, Light Blue, Dark Blue, Lavender, Yellow Green, Ocean Blue, Sky Blue,
Purple, Light Red, Red, Beige, Gray, Brown, Tan, Orange, Bronze.

## License

MIT License - see [LICENSE](LICENSE) file for details.

## Author

Alex Kilimnik

## Disclaimer

This is an unofficial third-party application. It is not affiliated with,
endorsed by, or supported by Qidi Technology.

## Version

- 0.3 - Full material table: all 35 QIDI codes; corrected code 41 (PETG Rapido) and 24 (UltraPA)
- 0.2 - Hexadecimal encoding fix
- 0.1 - Initial release
