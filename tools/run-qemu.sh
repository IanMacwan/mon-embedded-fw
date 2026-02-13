#!/usr/bin/env bash
set -euo pipefail

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
PROJECT_ROOT="$(cd "$SCRIPT_DIR/.." && pwd)"

TARGET="firmware"
QEMU_MACHINE="lm3s6965evb"
GDB_PORT=1234

ELF_PATH="$PROJECT_ROOT/${TARGET}.elf"

echo "🧹 cleaning previous build..."
make -C "$PROJECT_ROOT" clean

echo "⚡ building elf..."
make -C "$PROJECT_ROOT" all

echo "🚀 starting qemu..."
qemu-system-arm \
    -M "$QEMU_MACHINE" \
    -serial stdio \
    -kernel "$ELF_PATH" \
    -S -gdb "tcp::${GDB_PORT}"

echo "✅ exiting!"
