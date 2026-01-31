#pragma once
#include "types.h"

#define UART0_BASE 0x4000C000
#define UART0_DR (*(volatile uint32_t*)(UART0_BASE + 0x00))
#define UART0_FR (*(volatile uint32_t*)(UART0_BASE + 0x18))

void uart_init(void);
void uart_write(char c);
void uart_print(const char *s);
