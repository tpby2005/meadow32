#ifndef ISR_H
#define ISR_H

#include <stdint.h>
#include <stddef.h>

#include "vga.h"
#include "io.h"
#include "idt.h"
#include "pic.h"
#include "string.h"

typedef struct
{
    uint32_t __ignored, fs, es, ds;
    uint32_t edi, esi, ebp, esp, ebx, edx, ecx, eax;
    uint32_t int_no, err_no;
    uint32_t eip, cs, eflags, useresp, ss;
} Registers;

void isr_init();

#endif // ISR_H