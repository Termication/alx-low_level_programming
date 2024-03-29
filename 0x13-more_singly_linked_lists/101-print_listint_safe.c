#include "lists.h"
#include <stdio.h>
size_t looped_listint_len(const listint_t *head);
size_t print_listint_safe(const listint_t *head);
/**
 * looped_listint_len - Counts the number of unique nodes
 * in a looped listint_t linked list.
 * @head: A pointer to the head of the listint_t to check.
 *
 * Description:
 *	This function determines the number
 *	of unique nodes in a looped
 *	listint_t linked list. It uses
 *	Floyd's cycle-finding algorithm
 *	to detect the loop, and then
 *	calculates the number of unique nodes
 *	traversing the loop.
 *
 * Return: If the list is not looped - 0.
 * Otherwise - the number of unique nodes in the list.
 */
size_t looped_listint_len(const listint_t *head)
{
	const listint_t *slow_ptr, *fast_ptr;
	size_t nodes = 1;

	if (head == NULL || head->next == NULL)
		return (0);
	slow_ptr = head->next;
	fast_ptr = (head->next)->next;
	while (fast_ptr)
	{
		if (slow_ptr == fast_ptr)
		{
			slow_ptr = head;
			while (slow_ptr != fast_ptr)
			{
				nodes++;
				slow_ptr = slow_ptr->next;
				fast_ptr = fast_ptr->next;
			}
			slow_ptr = slow_ptr->next;
			while (slow_ptr != fast_ptr)
			{
				nodes++;
				slow_ptr = slow_ptr->next;
			}
			return (nodes);
		}
		slow_ptr = slow_ptr->next;
		fast_ptr = (fast_ptr->next)->next;
	}
	return (0);
}
/**
 * print_listint_safe - Prints a listint_t list safely.
 * @head: A pointer to the head of the listint_t list.
 *
 * Description:
 *	This function prints a listint_t
 *	list safely, detecting loops if
 *	present to avoid infinite loops.
 *	It utilizes the looped_listint_len
 *	function to determine if a loop is
 *	present, and if so, prints the
 *	nodes up to the loop and then
 *	indicates the loop node.
 *
 * Return: The number of nodes in the list.
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t nodes, idx = 0;

	nodes = looped_listint_len(head);
	if (nodes == 0)
	{
		for (; head != NULL; nodes++)
		{
			printf("[%p] %d\n", (void *)head, head->n);
			head = head->next;
		}
	}
	else
	{
		for (idx = 0; idx < nodes; idx++)
		{
			printf("[%p] %d\n", (void *)head, head->n);
			head = head->next;
		}
		printf("-> [%p] %d\n", (void *)head, head->n);
	}
	return (nodes);
}
