#include "lists.h"
/*
 * print_dlistint - Prints all the elements of a doubly linked list
 * @h: Pointer to the head of the doubly linked list
 * Description: This function prints all the elements
 * of a doubly linked list starting from
 * the given head pointer
 * Return: The total number of nodes in the doubly linked list.
 */
size_t print_dlistint(const dlistint_t *h)
{
	int node_count; /* Variable to count the nodes */

	node_count = 0;

	if (h == NULL)
		return (node_count);

	while (h->prev != NULL)
		h = h->prev;

	while (h != NULL)
	{
		printf("%d\n", h->n);
		node_count++;
		h = h->next;
	}

	return (node_count);
}
