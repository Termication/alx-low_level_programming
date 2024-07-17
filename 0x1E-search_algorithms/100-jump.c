#include <stdio.h>
#include <stddef.h>
#include <math.h>

/**
 * jump_search - Searches for a value in a sorted
 * array of integers using the Jump search algorithm
 * @array: Pointer to the first element of the array to search in
 * @size: Number of elements in the array
 * @value: Value to search for
 *
 * Return: The first index where value is located,
 * or -1 if not found or array is NULL
 */
int jump_search(int *array, size_t size, int value)
{
	if (array == NULL || size == 0)
		return (-1);

	size_t step = sqrt(size);
	size_t prev = 0;
	size_t curr = 0;

	while (curr < size && array[curr] < value)
	{
		printf("Value checked array[%zu] = [%d]\n", curr, array[curr]);
		prev = curr;
		curr += step;
	}

	printf("Value found between indexes [%zu] and [%zu]\n", prev, curr);

	for (size_t i = prev; i < size && i <= curr; i++)
	{
		printf("Value checked array[%zu] = [%d]\n", i, array[i]);
		if (array[i] == value)
			return ((int)i);
	}

	return (-1);
}

