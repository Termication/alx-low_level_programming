#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * _strdup - duplicates a string to a new memory space location
 * @str: input string
 * Return: Pointer to the duplicated string
 */
char *_strdup(char *str)
{
	char *duplicate_str;
	int i, length = 0;

	if (str == NULL)
		return (NULL);

	i = 0;
	while (str[i] != '\0')
		i++;

	length = i;

	duplicate_str = malloc(sizeof(char) * (length + 1));

	if (duplicate_str == NULL)
		return (NULL);

	for (i = 0; str[i]; i++)
		duplicate_str[i] = str[i];

	return (duplicate_str);
}
