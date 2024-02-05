#include "lists.h"

/**
 * add_nodeint_end - Appends a new node with specified
 * data at the end of a linked list
 * @head: Pointer to the first element in the list
 * @n: Data to be inserted in the new element
 *
 * Return: Pointer to the newly created node,
 * or NULL on memory allocation failure
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *new_node;
	listint_t *current_node = *head;

	new_node = malloc(sizeof(listint_t));
	if (!new_node)
		return (NULL);

	new_node->n = n;
	new_node->next = NULL;

	if (*head == NULL)
	{
		*head = new_node;
		return (new_node);
	}

	while (current_node->next)
		current_node = current_node->next;

	current_node->next = new_node;
	return (new_node);
}
