#ifndef STDLIB_H
#define STDLIB_H

#include <stddef.h>

void *memcpy(void *dest, const void *src, size_t n);
void bzero(void *s, size_t n);
char *itoa(int value, char *str, int base);

#endif