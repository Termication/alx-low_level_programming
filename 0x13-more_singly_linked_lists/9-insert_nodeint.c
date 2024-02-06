#include "lists.h"
/**
 * insert_nodeint_at_index - Adds a new node to a linked list
 * at a specified index
 * @head: Pointer to the first node in the list
 * @idx: Index where the new node is to be added
 * @n: Data to insert into the new node
 *
 * Return: Pointer to the new node, or NULL if insertion fails
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	unsigned int i;
	listint_t *new_node;
	listint_t *current_node = *head;

	new_node = malloc(sizeof(listint_t));
	if (!new_node)
		return (NULL);
	new_node->n = n;
	if (idx == 0)
	{
		new_node->next = *head;
		*head = new_node;
		return (new_node);
	}
	for (i = 0; current_node && i < idx - 1; i++)
		current_node = current_node->next;
	if (!current_node)
	{
		free(new_node);
		return (NULL);
	}
	new_node->next = current_node->next;
	current_node->next = new_node;
	return (new_node);
}
