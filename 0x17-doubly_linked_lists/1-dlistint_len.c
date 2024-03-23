#include "lists.h"
/**
 * dlistint_len - Counts the number of elements
 * in a doubly linked list.
 * @h: Pointer to the head of the list.
 *
 * Return: The number of elements in the list.
 */
size_t dlistint_len(const dlistint_t *h)
{
	int element_count;

	element_count = 0;

	if (h == NULL)
		return (element_count);

	while (h->prev != NULL)
		h = h->prev;

	while (h != NULL)
	{
		element_count++;
		h = h->next;
	}

	return (element_count);
}
