#include "lists.h"
/**
 * delete_nodeint_at_index - Removes a node frm
 * a linked list at the specified index
 * @head: Pointer to the pointer to the first node of the list
 * @index: Index of the node to be removed
 *
 * This function removes the node at the given index in the linked list.
 *
 * Return: 1 if successful, -1 if failed
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *prev_node = *head;
	listint_t *target_node = NULL;
	listint_t *next_node = NULL;
	unsigned int count = 0;

	if (*head == NULL)
		return (-1);
	if (index == 0)
	{
		*head = (*head)->next;
		free(prev_node);
		return (1);
	}
	while (count < index - 1)
	{
		if (!prev_node || !(prev_node->next))
			return (-1);
		prev_node = prev_node->next;
		count++;
	}
	target_node = prev_node->next;
	next_node = target_node->next;
	prev_node->next = next_node;
	free(target_node);
	return (1);
}
