#include "lists.h"
/**
 * free_listint - function that frees a linked list
 * @head: pointer to the head of the list to be freed
 */
void free_listint(listint_t *head)
{
	listint_t *current_node;

	while (head)
	{
		current_node = head->next;
		free(head);
		head = current_node;
	}
}
