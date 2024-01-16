#include "main.h"
#include <stdlib.h>

/**
 * str_concat - get ends of input and add together for size
 * @s1: arg input one
 * @s2: arg input two to concat
 * Return: concat of s1 and s2
 */
char *str_concat(char *s1, char *s2)
{
	char *result;
	int i, index;

	if (s1 == NULL)
		s1 = "";

	if (s2 == NULL)
		s2 = "";

	i = index = 0;

	while (s1[i] != '\0')
		i++;

	while (s2[index] != '\0')
		index++;

	result = malloc(sizeof(char) * (i + index + 1));

	if (result == NULL)
		return (NULL);

	i = index = 0;

	while (s1[i] != '\0')
	{
		result[i] = s1[i];
		i++;
	}

	while (s2[index] != '\0')
	{
		result[i] = s2[index];
		i++, index++;
	}

	result[i] = '\0';

	return (result);
}
