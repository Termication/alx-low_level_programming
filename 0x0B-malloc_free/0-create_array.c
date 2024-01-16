#include "main.h"
#include <stdlib.h>

/**
 * create_array - create array of size size and assign char c
 * @size: size of array
 * @c: char to assign
 *
 * Description: creates array of size 'size' and assigns char 'c'
 * Return: pointer to array, NULL if none
 */

char *create_array(unsigned int size, char c)
{
	char *str;
	unsigned int index;

	str = malloc(sizeof(char) * size);

	if (size == 0 || str == NULL)
		return (NULL);

	for (index = 0; index < size; index++)
		str[index] = c;

	return (str);
}
