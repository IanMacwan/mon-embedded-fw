#!/bin/bash
set -e

TARGET="firmware"
BUILD_DIR="build"
QEMU_MACHINE="lm3s6965evb"
GDB_PORT=1234

cd ..

echo "🧹 cleaning previous build..."
make clean

echo "⚡ building elf..."
make all

echo "🔧 converting elf -> raw binary..."
arm-none-eabi-objcopy -O binary "${TARGET}.elf" "${TARGET}.bin"

echo "🚀 starting qemu..."
qemu-system-arm -M $QEMU_MACHINE -serial stdio -kernel "${TARGET}.bin" -S -gdb tcp::${GDB_PORT}

echo "✅ finished!"
