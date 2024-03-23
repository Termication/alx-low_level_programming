#include "lists.h"
/**
 * delete_dnodeint_at_index - Removes the node at the given index from a
 * doubly linked list.
 *
 * @head: Pointer to a pointer to the head of the list.
 * @index: Index of the node to be removed.
 * Return: 1 if the removal succeeded, -1 if it failed.
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *current;
	dlistint_t *previous;
	unsigned int position;

	current = *head;

	if (current != NULL)
		while (current->prev != NULL)
			current = current->prev;

	position = 0;

	while (current != NULL)
	{
		if (position == index)
		{
			if (position == 0)
			{
				*head = current->next;
				if (*head != NULL)
					(*head)->prev = NULL;
			}
			else
			{
				previous->next = current->next;

				if (current->next != NULL)
					current->next->prev = previous;
			}

			free(current);
			return (1);
		}
		previous = current;
		current = current->next;
		position++;
	}

	return (-1);
}
