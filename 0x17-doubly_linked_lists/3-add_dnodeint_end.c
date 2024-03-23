#include "lists.h"
/**
 * add_dnodeint_end - Adds a new node at the
 * end of a doubly linked list.
 * @head: Pointer to a pointer to the head of the list.
 * @n: Value to be stored in the new node.
 *
 * Return: Address of the new node, or NULL if it fails.
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *last_node; /* Pointer to the last node */
	dlistint_t *new_node; /* Pointer to the new node */

	new_node = malloc(sizeof(dlistint_t));
	if (new_node == NULL)
		return (NULL);

	new_node->n = n;
	new_node->next = NULL;

	last_node = *head;

	if (last_node != NULL)
	{
		while (last_node->next != NULL)
			last_node = last_node->next;
		last_node->next = new_node;
	}
	else
	{
		*head = new_node;
	}

	new_node->prev = last_node;

	return (new_node);
}
