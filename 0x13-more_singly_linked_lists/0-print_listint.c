#include "lists.h"
#include <stdlib.h>

/**
 * print_listint - Prints all the elements of a linked list.
 * @h: Pointer to the head of the listint_t linked list.
 *
 * This function traverses the linked list starting from the head
 * and prints the integer value stored in each node.
 *
 * Return: The number of nodes in the linked list.
 */
size_t print_listint(const listint_t *h)
{
	size_t count;

	if (h == NULL)
	{
		return (0);
	}

	for (count = 0; h != NULL; count++)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
	return (count);
}
