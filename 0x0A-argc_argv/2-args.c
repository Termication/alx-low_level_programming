#include <stdio.h>
#include "main.h"

/**
 * main - function that prints all args content
 * @argc: argument one count
 * @argv: argument vector
 *
 * Return: Always 0
 */

int main(int argc, char *argv[])
{
	int k;

	for (k = 0; k < argc; k++)
	{
		printf("%s\n", argv[k]);
	}

	return (0);
}
