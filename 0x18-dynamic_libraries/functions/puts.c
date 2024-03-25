#include "main.h"

/**
 * _puts - prints a string to stdout.
 * @str: first arg the string to be printed.
 * _putchar and a new line
 */
void _puts(char *str)
{
	while (*str)
		_putchar(*str++);

	_putchar('\n');
}
