extern int main(void);
extern unsigned long _estack;

void Reset_Handler(void);
void Default_Handler(void);

// force vector table in .isr_vector section in flash (top) 
__attribute__((section(".isr_vector")))
void (*vector_table[])(void) = {
  (void (*)(void))(&_estack), // _estack not a func, however we pretend it is
  Reset_Handler
};

void Reset_Handler(void) {
  main();
  while (1);
}

void Default_Handler(void) {
  while (1);
}
