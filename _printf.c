#include <unistd.h>
#include <stdarg.h>
#include "main.h"

/**
 * _printf - Produces output according to a format, handling
 * the c, s, and %% conversion specifiers
 * @format: The format string containing zero or more directives
 *
 * Return: The number of characters printed (excluding the null byte),
 * or -1 if format is NULL
 */
int _printf(const char *format, ...)
{
	printf_spec_t specifiers[] = {
		{'c', print_char},
		{'s', print_string},
		{'%', print_percent},
		{'\0', NULL}
	};
	va_list args;
	int i, j, count, found;

	if (format == NULL)
		return (-1);

	va_start(args, format);
	count = 0;

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			write(1, &format[i], 1);
			count++;
			continue;
		}

		found = 0;
		for (j = 0; specifiers[j].spec != '\0'; j++)
		{
			if (format[i + 1] == specifiers[j].spec)
			{
				count += specifiers[j].f(args);
				found = 1;
				break;
			}
		}

		if (found)
		{
			i++;
			continue;
		}

		write(1, &format[i], 1);
		count++;
		if (format[i + 1] != '\0')
		{
			i++;
			write(1, &format[i], 1);
			count++;
		}
	}

	va_end(args);
	return (count);
}
