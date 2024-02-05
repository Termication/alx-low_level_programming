#include "lists.h"

/**
 * add_nodeint - Inserts a new node with specified
 * data at the beginning of a linked list
 * @head: Pointer to the initial node in the list
 * @n: Data to be stored in the new node
 *
 * Return: Pointer to the newly created node,
 * or NULL on memory allocation failure
 */
listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *new_node;

	new_node = malloc(sizeof(listint_t));
	if (!new_node)
		return (NULL);

	new_node->n = n;
	new_node->next = *head;
	*head = new_node;

	return (new_node);
}
