#include "pic.h"

void pic_init()
{
    outb(0x20, 0x11);
    outb(0xA0, 0x11);

    outb(0x21, 0x20);
    outb(0xA1, 0x28);

    outb(0x21, 0x04);
    outb(0xA1, 0x02);

    outb(0x21, 0x01);
    outb(0xA1, 0x01);

    outb(0x21, 0x00);
    outb(0xA1, 0x00);
}

void pic_send_eoi(uint8_t irq)
{
    if (irq >= 8)
        outb(0xA0, 0x20);

    outb(0x20, 0x20);
}