#include <stdio.h>
#include "main.h"
#include <stdlib.h>

/**
 * main - function that prints multiplication of two arg
 * @argc: argument one count
 * @argv: argument two vector
 *
 * Return: Always 0
 */
int main(int argc, char *argv[])
{
	int numb1, numb2 = 0;

	if (argc == 3)
	{
		numb1 = atoi(argv[1]);
		numb2 = atoi(argv[2]);
		printf("%d\n", numb1 * numb2);
	}
	else
	{
		printf("Error\n");
		return (1);
	}
	
	return (0);
}
