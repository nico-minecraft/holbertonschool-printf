#include <unistd.h>
#include "main.h"

/**
 * print_char - Prints a single character
 * @args: The va_list containing the character to print
 *
 * Return: The number of characters printed
 */
int print_char(va_list args)
{
	char c;

	c = (char)va_arg(args, int);
	write(1, &c, 1);
	return (1);
}

/**
 * print_string - Prints a string
 * @args: The va_list containing the string to print
 *
 * Return: The number of characters printed
 */
int print_string(va_list args)
{
	char *str;
	int i;

	str = va_arg(args, char *);
	if (str == NULL)
		str = "(null)";

	for (i = 0; str[i] != '\0'; i++)
		write(1, &str[i], 1);

	return (i);
}

/**
 * print_percent - Prints a percent sign
 * @args: The va_list (unused, but kept for consistent function pointer type)
 *
 * Return: The number of characters printed
 */
int print_percent(va_list args)
{
	char c;

	(void)args;
	c = '%';
	write(1, &c, 1);
	return (1);
}
