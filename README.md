# RGB Pico SATA Controller

This project is an open-source RGB controller designed to interface with 12v RGB devices using a Raspberry Pi Pico microcontroller. It features custom firmware and hardware, supporting the OpenRGB protocol for seamless integration with popular RGB control software.

RGB Pico SATA Controller is an open-source hardware and firmware project that enables control of standard (dumb) 12V RGB devices (such as common 12V RGB LED strips and PC lighting) using a Raspberry Pi Pico microcontroller. The controller connects via a SATA power connector for easy integration into PC builds and communicates with the OpenRGB desktop application using the OpenRGB protocol. This allows users to synchronize and customize their RGB lighting through a unified software interface.

The project includes:
- Custom PCB design (KiCad)
- Firmware written in C for the Raspberry Pi Pico
- Support for OpenRGB protocol for cross-platform compatibility

## Features
- Control standard (dumb) 12V RGB LEDs (common anode, 4-pin) via SATA power connector
- Seamless integration with OpenRGB software
- USB HID communication for low-latency control
- Open-source hardware (schematic, PCB, Gerber files)
- Easy-to-build firmware with CMake
- Designed for PC modding and custom lighting projects

## Folder Structure
- `Firmware/` — Source code for the Pico firmware (C, CMake)
- `Gerber/` — PCB manufacturing files for the controller
- `RGB_PICO_SATA_CONTROLLER.kicad_*` — KiCad schematic and PCB design files

## Hardware Overview
The hardware consists of a custom PCB designed in KiCad, featuring:
- Raspberry Pi Pico (RP2040) microcontroller
- SATA power input for 12V supply
- MOSFET drivers for switching 12V power to each RGB channel
- 4-pin connectors for standard 12V RGB LED strips (common anode)

All design files are provided in the repository (`.kicad_sch`, `.kicad_pcb`, and Gerber files).
## Getting Started
### Hardware
1. Open the KiCad project files (`RGB_PICO_SATA_CONTROLLER.kicad_sch`, `.kicad_pcb`) to view or modify the schematic and PCB layout.
2. Use the Gerber files in the `Gerber/` directory to order PCBs from your preferred manufacturer.
3. Assemble the board using the schematic and bill of materials (BOM).
4. Solder the Raspberry Pi Pico and connectors as indicated.

### Firmware
1. Install the Raspberry Pi Pico SDK and required toolchain (CMake, GCC, etc.).
2. Clone this repository and navigate to the `Firmware/` directory.
3. Build the firmware:
   ```sh
   mkdir build
   cd build
   cmake ..
   make
   ```
4. Connect your Pico in BOOTSEL mode and copy the generated `.uf2` file to the Pico's USB drive.

### Software (OpenRGB)
1. Download and install the OpenRGB application from [openrgb.org](https://openrgb.org/).
2. Connect the RGB Pico SATA Controller to your PC via USB.
3. Open OpenRGB and the controller should appear as a supported device.
4. Configure and control your RGB devices through the OpenRGB interface.

## OpenRGB Protocol
The firmware implements the OpenRGB protocol, allowing the controller to be recognized and managed by the OpenRGB desktop application. For protocol details, see `Firmware/openrgb_protocol.c` and `Firmware/openrgb_protocol.h`.

## License
## Contributing
Contributions are welcome! Please open issues or pull requests for bug fixes, new features, or suggestions.

## License
[Specify your license here, e.g., MIT, GPL, etc.]

---
Feel free to contribute or open issues for suggestions and improvements.