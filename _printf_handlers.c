#include "main.h"

/**
 * print_char - prints a single character
 * @args: list of variadic arguments, next one is the char to print
 *
 * Return: the number of characters printed
 */
int print_char(va_list args)
{
	char c;

	c = va_arg(args, int);

	return (_putchar(c));
}

/**
 * print_string - prints a string
 * @args: list of variadic arguments, next one is the string to print
 *
 * Return: the number of characters printed
 */
int print_string(va_list args)
{
	char *str;
	int i;

	str = va_arg(args, char *);
	i = 0;

	if (str == NULL)
		str = "(null)";

	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
	}

	return (i);
}

/**
 * print_percent - prints a literal percent sign
 * @args: list of variadic arguments (unused)
 *
 * Return: the number of characters printed
 */
int print_percent(va_list args)
{
	(void)args;

	return (_putchar('%'));
}

/**
 * get_print_func - matches a conversion specifier to its handler
 * @c: the conversion specifier character
 *
 * Return: a pointer to the matching handler function,
 * or NULL if no handler matches c
 */
int (*get_print_func(char c))(va_list)
{
	int i;
	print_t funcs[] = {
		{'c', print_char},
		{'s', print_string},
		{'%', print_percent},
		{0, NULL}
	};

	i = 0;
	while (funcs[i].specifier != 0)
	{
		if (funcs[i].specifier == c)
			return (funcs[i].func);
		i++;
	}

	return (NULL);
}
