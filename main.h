#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define BUFF 1024

/* functions */
int print_char(va_list args);

/* handles different inputs */
int _controller(va_list args, const char *string);
int percent(va_list args, const char *String, int *count);

/* print to stdout */
int _write(char c);
int _printf(const char *format, ...);

#endif
