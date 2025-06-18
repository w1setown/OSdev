#ifndef STDIO_H
#define STDIO_H

void putc(unsigned char c);
unsigned char getc(void);
void puts(const char* str);
void gets(char* str, int maxlen);

#endif