#include "../../inc/timer.h"
#include "../../inc/uart.h"

static volatile uint32_t system_ticks = 0;

uint32_t timer_get_ticks(void) {
    return system_ticks;
}

void timer_init(void) {
  SYSCTL_RCGC1 |= (1 << 16); // Enable Timer0 clock
  TIMER0_CTL = 0; // Disable timer
  TIMER0_CFG = 0; // 32-bit mode
  TIMER0_TAMR = 0x2; // Periodic mode
  TIMER0_TAILR = 16000000; // 1 second at 16 MHz
  TIMER0_IMR = 1; // Enable timeout interrupt
  NVIC_EN0 |= (1 << 19); // Enable interrupt in NVIC (IRQ 19)
  TIMER0_CTL |= 1; // Enable timer
}

void Timer0_Handler(void) {
  TIMER0_ICR = 1;
  system_ticks++;
  uart_print("Tick\n");
}
