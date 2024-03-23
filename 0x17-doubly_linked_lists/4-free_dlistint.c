#include "lists.h"
/**
 * free_dlistint - Frees a doubly linked list.
 * @head: Pointer to the head of the list.
 *
 * Description: This function frees all
 * the nodes of a doubly linked list.
 * It starts from the head and iteratively
 * frees each node until the end.
 */
void free_dlistint(dlistint_t *head)
{
	dlistint_t *current;

	if (head != NULL)
		while (head->prev != NULL)
			head = head->prev;

	while ((current = head) != NULL)
	{
		head = head->next;
		free(current);
	}
}
