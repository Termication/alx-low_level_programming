#include <stdio.h>
#include "main.h"
#include <stdlib.h>
#include <string.h>

/**
 * main - function that prints addition of two arg
 * @argc: argument one count
 * @argv: argument two vector
 *
 * Return: Always 0
 */
int main(int argc, char *argv[])
{
	int numb1;
	unsigned int numb2, sum = 0;
	char *k;

	if (argc > 1)
	{
		for (numb1 = 1; numb1 < argc; numb1++)
		{
			k = argv[numb1];

			for (numb2 = 0; numb2 < strlen(k); numb2++)
			{
				if (k[numb2] < 48 || k[numb2] > 57)
				{
					printf("Error\n");
					return (1);
				}
			}
			sum += atoi(k);
			k++;
		}

		printf("%d\n", sum);
	}
	else
	{
		printf("0\n");
	}
	return (0);
}
