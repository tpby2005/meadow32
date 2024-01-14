#include "isr.h"

char keycode_table[] = {
    0,
    27,
    '1',
    '2',
    '3',
    '4',
    '5',
    '6',
    '7',
    '8',
    '9',
    '0',
    '-',
    '=',
    '\b',
    '\t',
    'q',
    'w',
    'e',
    'r',
    't',
    'y',
    'u',
    'i',
    'o',
    'p',
    '[',
    ']',
    '\n',
    0,
    'a',
    's',
    'd',
    'f',
    'g',
    'h',
    'j',
    'k',
    'l',
    ';',
    '\'',
    '`',
    0,
    '\\',
    'z',
    'x',
    'c',
    'v',
    'b',
    'n',
    'm',
    ',',
    '.',
    '/',
    0,
    '*',
    0,
    ' ',
    0,
};

void _isr33(Registers *regs)
{
    asm volatile("cli");
    asm volatile("pusha");

    terminal_writestring("Keyboard interrupt occured.");

    uint8_t status;
    char keycode;

    outb(0x20, 0x20);

    status = inb(0x64);

    if (status & 0x01)
    {
        keycode = inb(0x60);

        if (keycode < 0)
        {
            return;
        }

        if (keycode & 0x80)
        {
            // key released
        }

        else
        {
            char c = keycode_table[keycode];

            // terminal_writestring(&c);
            terminal_writestring("Key pressed!");
        }
    }

    asm volatile("popa");
    asm volatile("sti");
    asm volatile("iret");
}

void default_isr(Registers *regs)
{
    asm volatile("cli");
    asm volatile("pusha");

    outb(0x20, 0x20);

    if (regs->int_no >= 40)
    {
        outb(0xA0, 0x20);
    }

    asm volatile("popa");
    asm volatile("sti");
    asm volatile("iret");
}

void *isr_routines[256];

void isr_install()
{
    for (int i = 0; i < 256; i++)
    {
        isr_routines[i] = default_isr;

        if (i == 33)
        {
            isr_routines[i] = _isr33;
            idt_set(i, (uint32_t)_isr33, 0x08, 0x8E);
        }

        else
        {
            idt_set(i, (uint32_t)default_isr, 0x08, 0x8E);
        }
    }
}

void isr_init()
{
    pic_init();
    isr_install();
}