#include "idt.h"

IDT idt;
IDT_Ptr idt_ptr;

void idt_load()
{
    idt_init();

    asm volatile("lidt %0" : : "m"(idt_ptr));

    asm volatile("sti");
}

void idt_set(uint8_t num, uint32_t base, uint16_t sel, uint8_t flags)
{
    idt.entries[num].offset_low = (base & 0xFFFF);
    idt.entries[num].offset_high = (base >> 16) & 0xFFFF;

    idt.entries[num].selector = sel;
    idt.entries[num].zero = 0;

    idt.entries[num].type_attr = flags;
}

void idt_init()
{
    idt_ptr.limit = sizeof(IDT_Entry) * 256 - 1;
    idt_ptr.base = (uint32_t)&idt.entries;

    memset(&idt.entries, 0, sizeof(IDT_Entry) * 256);
}