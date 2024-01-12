#include <stdio.h>
#include "main.h"

/**
 * main - Prints the number of the arg
 * @argc: arg one
 * @argv: arg two
 *
 * Return: always 0
 */

int main(int argc, char *argv[])
{
	(void) argv;
	printf("%d\n", argc - 1);

	return (0);
}
