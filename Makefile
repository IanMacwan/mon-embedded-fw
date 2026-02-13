CC      := arm-none-eabi-gcc
OBJCOPY := arm-none-eabi-objcopy

TARGET  := firmware
BUILD   := build

SRC_DIR     := src
STARTUP_DIR := startup
INC_DIR     := inc
LINKER_DIR  := linker

LINKER_SCRIPT := $(LINKER_DIR)/cortex-m3.ld

SRCS := \
	$(STARTUP_DIR)/startup.c \
	$(SRC_DIR)/main.c \
	$(SRC_DIR)/drivers/uart.c \
	$(SRC_DIR)/drivers/timer.c

OBJS := $(SRCS:%.c=$(BUILD)/%.o)

CFLAGS := \
	-mcpu=cortex-m3 \
	-mthumb \
	-O0 -g \
	-ffreestanding \
	-fno-builtin \
	-nostdlib \
	-Wall -Wextra \
	-I$(INC_DIR)

LDFLAGS := \
	-T $(LINKER_SCRIPT)

all: $(TARGET).elf

$(TARGET).elf: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $@

$(BUILD)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD) $(TARGET).elf

flash: $(TARGET).elf
	@echo "Flash command goes here"

.PHONY: all clean flash

