#include "function_pointers.h"
#include <stdio.h>

/**
 * array_iterator - applies a given function to each element of an array
 * @array: array of integers
 * @size: size of the array
 * @action: pointer to the function to apply
 *
 * Description: This function takes an array of int,
 *  the size of the array,
 * and a function pointer.
 */
void array_iterator(int *array, size_t size, void (*action)(int))
{
	unsigned int index;

	if (array == NULL || action == NULL)
		return;

	for (index = 0; index < size; index++)
	{
		action(array[index]);
	}
}
