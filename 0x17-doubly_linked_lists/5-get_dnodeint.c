#include "lists.h"
/**
 * get_dnodeint_at_index - Returns the node at a
 * given index in a doubly linked list.
 * @head: Pointer to the head of the list.
 * @index: Index of the node to return.
 *
 * Return: Pointer to the node at the
 * specified index, or NULL if it fails.
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	unsigned int position;

	if (head == NULL)
		return (NULL);

	while (head->prev != NULL)
		head = head->prev;

	position = 0;

	while (head != NULL)
	{
		if (position == index)
			break;
		head = head->next;
		position++;
	}

	return (head);
}
