#include "lists.h"
/**
 * sum_dlistint - Calculates the sum of all
 * the data (n) of a doubly linked list.
 * @head: Pointer to the head of the list.
 *
 * Description: This function traverses a doubly
 * linked list and calculates the
 * sum of all the data (n)
 * Return: The sum of all the data (n) in the list.
 */
int sum_dlistint(dlistint_t *head)
{
	int total_sum;

	total_sum = 0;

	if (head != NULL)
	{
		while (head->prev != NULL)
			head = head->prev;

		while (head != NULL)
		{
			total_sum += head->n;
			head = head->next;
		}
	}

	return (total_sum);
}
