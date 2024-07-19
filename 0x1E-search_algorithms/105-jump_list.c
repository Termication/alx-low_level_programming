#include "search_algos.h"
#include <math.h>

/**
 * jump_list - Searches for a value in a sorted singly linked list using the Jump search algorithm.
 * @list: Pointer to the head of the list.
 * @size: The number of nodes in the list.
 * @value: The value to search for.
 *
 * Return: A pointer to the first node where the value is located, or NULL if the value is not present or the list is NULL.
 */
listint_t *jump_list(listint_t *list, size_t size, int value)
{
	size_t index, k, m;
	listint_t *prev;

	if (list == NULL || size == 0)
		return (NULL);

	m = (size_t)sqrt((double)size);  /* Calculate the jump step */
	index = 0;
	k = 0;

	do {
		prev = list;
		k++;
		index = k * m;

		/* Move list pointer to the next block */
		while (list->next && list->index < index)
			list = list->next;

		/* Adjust index if we've reached the end of the list */
		if (list->next == NULL && index != list->index)
			index = list->index;

		printf("Value checked at index [%d] = [%d]\n", (int)index, list->n);

	} while (index < size && list->next && list->n < value);

	printf("Value found between indexes [%d] and [%d]\n", (int)prev->index, (int)list->index);

	/* Linear search within the identified block */
	for (; prev && prev->index <= list->index; prev = prev->next)
	{
		printf("Value checked at index [%d] = [%d]\n", (int)prev->index, prev->n);
		if (prev->n == value)
			return (prev);
	}

	return (NULL);
}
