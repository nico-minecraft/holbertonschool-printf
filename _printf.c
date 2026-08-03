#include "main.h"

/**
 * _printf - produces output according to a format, handling the
 * c, s and %% conversion specifiers
 * @format: character string composed of zero or more directives
 *
 * Return: the number of characters printed (excluding the
 * null byte), or -1 on failure
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count;
	int i;
	int (*f)(va_list);

	if (format == NULL)
		return (-1);

	va_start(args, format);
	count = 0;
	i = 0;

	while (format[i] != '\0')
	{
		if (format[i] != '%')
		{
			count += _putchar(format[i]);
			i++;
			continue;
		}

		i++;
		if (format[i] == '\0')
			break;

		f = get_print_func(format[i]);
		if (f != NULL)
			count += f(args);
		else
		{
			count += _putchar('%');
			count += _putchar(format[i]);
		}
		i++;
	}

	va_end(args);
	return (count);
}
