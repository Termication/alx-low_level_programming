#include "function_pointers.h"

/**
 * int_index - searches for an integer using a comparison function
 * @array: array of integers
 * @size: number of elements in the array
 * @cmp: pointer to the comparison function
 *
 * Return: the index of the first matching element, or -1 if no match.
 */
int int_index(int *array, int size, int (*cmp)(int))
{
	int index;

	if (array == NULL || size <= 0 || cmp == NULL)
		return (-1);

	for (index = 0; index < size; index++)
	{
		if (cmp(array[index]))
			return (index);
	}

	return (-1);
}
