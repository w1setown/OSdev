#include "common/stdio.h"
#include "kernel/uart.h"

void putc(unsigned char c)
{
    uart_putc(c);
}

unsigned char getc(void)
{
    return uart_getc();
}

void puts(const char* str)
{
    uart_puts(str);
}

void gets(char* str, int maxlen)
{
    int i = 0;
    unsigned char c;
    
    while (i < maxlen - 1) {
        c = getc();
        
        // Handle backspace
        if (c == '\b' || c == 127) {
            if (i > 0) {
                i--;
                putc('\b');
                putc(' ');
                putc('\b');
            }
            continue;
        }
        
        // Handle enter/return
        if (c == '\r' || c == '\n') {
            putc('\r');
            putc('\n');
            break;
        }
        
        // Regular character
        str[i++] = c;
        putc(c);
    }
    
    str[i] = '\0';
}