extern int main(void);
extern unsigned long _estack;

void Reset_Handler(void);
void Default_Handler(void);
void Timer0_Handler(void);

// force vector table in .isr_vector section in flash (top) 
__attribute__((section(".isr_vector")))
void (*vector_table[])(void) = {
  (void (*)(void))(&_estack), // _estack not a func, however we pretend it is
  Reset_Handler,
  0, 0, 0, 0, 0,
  Default_Handler, // NMI
  Default_Handler, // HardFault
  Default_Handler, // MemManage
  Default_Handler, // BusFault
  Default_Handler, // UsageFault
  0, 0, 0, 0, // Reserved
  Default_Handler, // SVCall
  Default_Handler, // Debug
  0, // Reserved
  Default_Handler, // PendSV
  Default_Handler, // SysTick
  /* External interrupts start at index 16 */
  [16 + 19] = Timer0_Handler
};

void Reset_Handler(void) {
  main();
  while (1);
}

void Default_Handler(void) {
  while (1);
}
