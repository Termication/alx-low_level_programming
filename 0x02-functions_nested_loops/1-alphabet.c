#include "main.h"

/**
 * main - function that prints the alphabet, in lowercase
 * Description: function that print from a to z
 * Return: 0
 */
void print_alphabet(void)
{
	char c;

	for (c = 'a'; c <= 'z'; c++)
	{
	_putchar(c);
	}
	_putchar('\n');
}
