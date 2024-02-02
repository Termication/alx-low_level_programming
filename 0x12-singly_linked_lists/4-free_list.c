#include <stdlib.h>
#include "lists.h"

/**
 * free_list - Frees the memory occupied by a linked list
 * @head: A pointer to the list_t list to be freed
 *
 * This function traverses the given linked list and frees the memory
 * occupied by each node, including the strings within the nodes.
 */
void free_list(list_t *head)
{
	list_t *temp;

	while (head)
	{
		temp = head->next;
		free(head->str);
		free(head);
		head = temp;
	}
}
