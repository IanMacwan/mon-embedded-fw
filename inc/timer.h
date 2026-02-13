#pragma once
#include "types.h"

#define TIMER0_BASE 0x40030000

#define TIMER0_CFG (*(volatile uint32_t*)(TIMER0_BASE + 0x000))
#define TIMER0_TAMR (*(volatile uint32_t*)(TIMER0_BASE + 0x004))
#define TIMER0_CTL (*(volatile uint32_t*)(TIMER0_BASE + 0x00C))
#define TIMER0_IMR (*(volatile uint32_t*)(TIMER0_BASE + 0x018))
#define TIMER0_ICR (*(volatile uint32_t*)(TIMER0_BASE + 0x024))
#define TIMER0_TAILR (*(volatile uint32_t*)(TIMER0_BASE + 0x028))

#define SYSCTL_RCGC1 (*(volatile uint32_t*)0x400FE104)
#define NVIC_EN0 (*(volatile uint32_t*)0xE000E100)

void timer_init(void);
uint32_t timer_get_ticks(void);
