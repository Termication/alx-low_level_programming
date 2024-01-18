#include <stdlib.h>
#include "main.h"

/**
 * array_range - creates an array of integers within a specified range
 * @min: the minimum value in the range
 * @max: the maximum value in the range
 *
 * Return: pointer to the new array
 */
int *array_range(int min, int max)
{
	int *ptr;
	int i, size;

	if (min > max)
		return (NULL);

	size = max - min + 1;

	ptr = malloc(sizeof(int) * size);

	if (ptr == NULL)
		return (NULL);

	for (i = 0; min <= max; i++)
		ptr[i] = min++;

	return (ptr);
}
