#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
/**
 * main - Entry point
 *
 * Description: Prints all single-digit numbers of base 10 starting from 0,
 * followed by a new line, using only putchar.
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	char digit;

	for (digit = '0'; digit <= '9'; digit++)
	{
		putchar(digit);
	}

	putchar('\n');

	return (0);
}
