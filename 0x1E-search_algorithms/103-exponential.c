#include "search_algos.h"
#include <stdio.h>
#include <stddef.h>

/**
 * print_array - Prints an array of integers
 * @array: The array to print
 * @low: The starting index
 * @high: The ending index
 */
void print_array(int *array, size_t low, size_t high)
{
    size_t i;

    printf("Searching in array: ");
    for (i = low; i <= high; i++)
    {
        printf("%d", array[i]);
        if (i < high)
            printf(", ");
    }
    printf("\n");
}

/**
 * binary_search - Searches for a value in a sorted array of integers
 *                 using the Binary search algorithm
 * @array: Pointer to the first element of the array to search in
 * @low: The starting index
 * @high: The ending index
 * @value: The value to search for
 *
 * Return: The index where value is located, or -1 if not found
 */
int binary_search(int *array, size_t low, size_t high, int value)
{
    size_t mid;

    while (low <= high)
    {
        print_array(array, low, high);
        mid = low + (high - low) / 2;

        if (array[mid] == value)
            return (int)mid;
        if (array[mid] < value)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}

/**
 * exponential_search - Searches for a value in a sorted array of integers
 *                      using the Exponential search algorithm
 * @array: Pointer to the first element of the array to search in
 * @size: The number of elements in the array
 * @value: The value to search for
 *
 * Return: The first index where value is located, or -1 if not found
 */
int exponential_search(int *array, size_t size, int value)
{
    size_t bound = 1;

    if (array == NULL)
        return -1;

    if (array[0] == value)
        return 0;

    while (bound < size && array[bound] <= value)
    {
        printf("Value checked array[%zu] = [%d]\n", bound, array[bound]);
        bound *= 2;
    }

    size_t low = bound / 2;
    size_t high = (bound < size) ? bound : size - 1;

    printf("Value found between indexes [%zu] and [%zu]\n", low, high);
    return binary_search(array, low, high, value);
}
