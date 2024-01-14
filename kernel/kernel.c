#include "vga.h"
#include "idt.h"
#include "isr.h"

void main(void)
{
    isr_init();
    idt_load();
    terminal_initialize();

    terminal_writestring("Hello, kernel World!\n");

    asm volatile("hlt");
}