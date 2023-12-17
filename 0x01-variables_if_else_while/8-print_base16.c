#include <unistd.h>
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
	char digit;
	int index;

	for (index = '0'; index <= '9'; index++)
	{
		putchar(index);
	}

	for (digit = 'a'; digit <= 'f'; digit++)
	{
		putchar(digit);
	}

	putchar('\n');

	return (0);
}
