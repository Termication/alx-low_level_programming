#include <stdio.h>

/**
 * main - Entry point
 *
 * Description: Prints the digits 0 to 9 and the lowercase alphabet from a to f.
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	char di;
	int i;

	for (i = '0'; i <= '9'; i++)
		putchar(i);

	for (di = 'a'; di <= 'f'; di++)
		putchar(di);

	putchar('\n');

	return (0);
}
