# Bare-Metal ARM Cortex-M Firmware (QEMU)

A minimal bare-metal firmware project targeting an ARM Cortex-M3, built and tested using QEMU.

This project demonstrates:

- Custom linker script and memory layout
- Startup code and vector table
- Memory-mapped UART driver
- Basic timer interrupt handling
- Debugging with GDB
- Fully freestanding (no standard library)

The firmware runs on QEMU’s `lm3s6965evb` Cortex-M3 board model.
