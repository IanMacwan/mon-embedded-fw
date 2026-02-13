#include "../inc/uart.h"
#include "../inc/timer.h"

int main(void) {
  uart_init();
  timer_init();

  uart_print("give orange me give eat orange me eat orange give me eat orange give me you.\n");

  while (1);
}
