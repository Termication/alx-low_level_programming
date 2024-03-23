#include "lists.h"
/**
 * add_dnodeint - Adds a new node at the
 * beginning of a doubly linked list.
 * @head: Pointer to a pointer to the head of the list.
 * @n: Value to be stored in the new node.
 *
 * Return: Address of the new node, or NULL if it fails.
 */
dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *new_node; /* Pointer to the new node */
	dlistint_t *current_head; /* Pointer to the current head */

	new_node = malloc(sizeof(dlistint_t));
	if (new_node == NULL)
		return (NULL);

	new_node->n = n;
	new_node->prev = NULL;
	current_head = *head;

	if (current_head != NULL)
	{
		while (current_head->prev != NULL)
			current_head = current_head->prev;
	}

	new_node->next = current_head;

	if (current_head != NULL)
		current_head->prev = new_node;

	*head = new_node;

	return (new_node);
}
