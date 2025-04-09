# Slily62 — A Custom Split Keyboard with Vial and QMK Firmware
![20241012_174241_e2](https://github.com/user-attachments/assets/0e6ab64e-80ad-4260-9f42-313033695ed7)

## Overview

The Slily62 is a fully custom-built ortholinear split mechanical keyboard featuring a 6×5+1 key matrix per side, LED underglow, and powered by RP2040 microcontrollers running QMK firmware with Vial support for real-time key remapping and configuration.

Designed for maximum flexibility and ease of use, the keyboard supports dynamic keymaps, multiple layers, and customizable RGB underglow — all configurable through the Vial GUI without the need to reflash firmware.

---

## Features

- 6×5+1 matrix split layout (7 columns per side)
- Powered by QMK Firmware
- Vial support for live key remapping and layer editing
- WS2812B underglow
- Per-layer RGB effects
- Independent left & right controllers (RP2040)
- Designed for USB-C TRRS split connection
- Multiple programmable layers
- Custom layout & hand-wiring friendly

> 3D printable case files are available in the `case/` folder.

---

## Build Instructions

Clone the [Vial fork of QMK firmware](https://github.com/vial-kb/vial-qmk):

```bash
git clone --recurse-submodules https://github.com/vial-kb/vial-qmk.git
cd vial-qmk
qmk setup
qmk compile -kb handwired/slily62 -km vial
qmk flash -kb handwired/slily62 -km vial
make handwired/slily62:vial
```

---

## Resources

- QMK Documentation: [https://docs.qmk.fm/](https://docs.qmk.fm/)
- Vial Project: [https://get.vial.today/](https://get.vial.today/)
- Vial App Download: [https://get.vial.today/download/](https://get.vial.today/download/)
- Vial Web Configurator: [https://vial.rocks/](https://vial.rocks/)

---

## Credits

Designed and developed by Aymen Alouache.

Inspired by open-source keyboard designs Lily58, Sofle, and Corne.

Built with ❤️ using QMK and Vial.
