#include <stdio.h>
#include <stddef.h>

/**
 * interpolation_search - Searches for a value in a sorted
 * array of integers
 * using the Interpolation search algorithm
 * @array: Pointer to the first element of the array to search in
 * @size: Number of elements in the array
 * @value: Value to search for
 *
 * Return: The first index where value is located, or
 * -1 if not found or array is NULL
 */
int interpolation_search(int *array, size_t size, int value)
{
	size_t position, start, end;
	double fraction;

	if (array == NULL)
		return (-1);

	start = 0;
	end = size - 1;

	while (start <= end && value >= array[start] && value <= array[end])
	{
		fraction = (double)(end - start) / (array[end]
				- array[start]) * (value - array[start]);
		position = (size_t)(start + fraction);
		printf("Value checked array[%zu]", position);

		if (position >= size)
		{
			printf(" is out of range\n");
			break;
		}
		else
		{
			printf(" = [%d]\n", array[position]);
		}

		if (array[position] == value)
			return ((int)position);

		if (array[position] < value)
			start = position + 1;
		else
			end = position - 1;
	}

	return (-1);
}

