#include <stdio.h>
#include <stddef.h>

/**
 * linear_search - a Function that ...
 * @array: Description of array.
 * @size: Description of size.
 * @value: Description of value.
 * Return: Description of the return value.
 */
int linear_search(int *array, size_t size, int value)
{
	if (array == NULL)
		return (-1);

	for (size_t i = 0; i < size; i++)
	{
		printf("Value checked array[%zu] = [%d]\n", i, array[i]);
		if (array[i] == value)
			return ((int)i);
	}
	return (-1);
}
