#ifndef IDT_H
#define IDT_H

#include <stdint.h>

#include "string.h"

typedef struct
{
    uint16_t offset_low;
    uint16_t selector;
    uint8_t zero;
    uint8_t type_attr;
    uint16_t offset_high;
} IDT_Entry __attribute__((packed));

typedef struct
{
    uint16_t limit;
    uint32_t base;
} IDT_Ptr __attribute__((packed));

typedef struct
{
    IDT_Entry entries[256];
    IDT_Ptr ptr;
} IDT __attribute__((packed));

void idt_set(uint8_t num, uint32_t base, uint16_t sel, uint8_t flags);

void idt_load();

#endif // IDT_H