#include "lists.h"
/**
 * insert_dnodeint_at_index - Inserts a new node at
 * a given position in a doubly linked list.
 * @h: Pointer to a pointer to the head of the list.
 * @idx: Index at which the new node should be inserted.
 * @n: Value to be stored in the new node.
 *
 * Description: This function inserts a new
 * node with the given value at the
 * specified index in a doubly linked list.
 * Return: Address of the new node, or NULL if it fails.
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *new_node; /* Pointer to the new node */
	dlistint_t *current; /* Pointer to the current node */
	unsigned int position; /* Position in the list */

	new_node = NULL;

	if (idx == 0)
		new_node = add_dnodeint(h, n);
	else
	{
		current = *h;
		position = 1;

		if (current != NULL)
			while (current->prev != NULL)
				current = current->prev;

		while (current != NULL)
		{
			if (position == idx)
			{
				if (current->next == NULL)
					new_node = add_dnodeint_end(h, n);
				else
				{
					new_node = malloc(sizeof(dlistint_t));
					if (new_node != NULL)
					{
						new_node->n = n;
						new_node->next = current->next;
						new_node->prev = current;
						current->next->prev = new_node;
						current->next = new_node;
					}
				}
				break;
			}
			current = current->next;
			position++;
		}
	}

	return (new_node);
}
