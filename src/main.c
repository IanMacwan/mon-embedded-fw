#include "../inc/uart.h"

int main(void) {
    uart_init();
    uart_print("hello world!!\n");

    while (1);
}
