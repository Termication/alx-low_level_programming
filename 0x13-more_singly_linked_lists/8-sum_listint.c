#include "lists.h"
/**
 * sum_listint - Computes the total sum of the
 * integer data in a listint_t list
 * @head: Pointer to the first node of the linked list
 *
 * Return: The resulting sum of the integer data
 */
int sum_listint(listint_t *head)
{
	int total = 0;
	listint_t *current_node = head;

	while (current_node)
	{
		total += current_node->n;
		current_node = current_node->next;
	}
	return (total);
}
