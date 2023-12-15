#include <stdio.h>

/**
 * main - This is the function of the task
 *
 * Description: This program prints the alphabet in lowercase and uppercase
 *
 * Return: 0
 */
int main(void)
{
	char i;

	for (i = 'a'; i <= 'z'; i++)
		putchar(i);

	putchar('\n');

	for (i = 'A'; i <= 'Z'; i++)
		putchar(i);

	putchar('\n');

	return (0);
}
