#include <stdio.h>
#include <limits.h>
#include "main.h"

/**
 * main - entry point, sanity-checks _printf against printf
 *
 * Return: always 0
 */
int main(void)
{
	int len, len2;

	len = _printf("Let's try %s a %c sentence with %d%% coverage.\n",
		      "printing", 'c', 42);
	len2 = printf("Let's try %s a %c sentence with %d%% coverage.\n",
		      "printing", 'c', 42);
	_printf("Length:[%d]\n", len);
	printf("Length:[%d]\n", len2);

	_printf("String:[%s]\n", "I am a string !");
	printf("String:[%s]\n", "I am a string !");

	_printf("Null string:[%s]\n", NULL);
	printf("Null string:[%s]\n", NULL);

	_printf("Just a percent: [%%]\n");
	printf("Just a percent: [%%]\n");

	_printf("Ints:[%d, %i, %d, %i]\n", 0, -762534, 1024, 98765);
	printf("Ints:[%d, %i, %d, %i]\n", 0, -762534, 1024, 98765);

	_printf("Extremes:[%d, %d]\n", INT_MIN, INT_MAX);
	printf("Extremes:[%d, %d]\n", INT_MIN, INT_MAX);

	_printf("No format at all\n");
	printf("No format at all\n");

	return (0);
}
