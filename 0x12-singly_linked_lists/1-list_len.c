#include <stdlib.h>
#include "lists.h"

/**
 * list_len - Counts the number of elements in a linked list
 * @h: A pointer to the list_t list
 *
 * This function traverses the given linked list and counts the number
 * of elements present.
 *
 * Return: The number of elements in the linked list.
 */
size_t list_len(const list_t *h)
{
	size_t elementCount = 0;

	while (h)
	{
		elementCount++;
		h = h->next;
	}

	return (elementCount);
}
