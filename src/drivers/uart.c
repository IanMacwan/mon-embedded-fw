#include "../../inc/uart.h"

void uart_init(void) {
    // QEMU takes care of init
}

void uart_write(char c) {
    UART0_DR = c;
}

void uart_print(const char *s) {
    while (*s) {
        uart_write(*s++);
    }
}
