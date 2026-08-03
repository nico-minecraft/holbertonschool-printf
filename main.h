#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>

/**
 * struct print - pairs a conversion specifier with its handler
 * @specifier: the conversion specifier character (c, s, %, ...)
 * @func: pointer to the function that handles that specifier
 *
 * Description: used to build a lookup table inside get_print_func
 */
typedef struct print
{
	char specifier;
	int (*func)(va_list);
} print_t;

int _printf(const char *format, ...);
int _putchar(char c);

int print_char(va_list args);
int print_string(va_list args);
int print_percent(va_list args);
int (*get_print_func(char c))(va_list);

#endif
