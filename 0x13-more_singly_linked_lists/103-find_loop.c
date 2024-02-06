#include "lists.h"

/**
 * find_listint_loop - Detects a loop in a linked list.
 * @head: The head of the linked list to search.
 *
 * Return: The address of the node where the loop starts, or NULL if no loop.
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *easy = head;
	listint_t *speedy = head;

	if (!head)
		return (NULL);

	while (easy && speedy && speedy->next)
	{
		easy = easy->next;
		speedy = speedy->next->next;

		if (easy == speedy)
		{
			easy = head;
			while (easy != speedy)
			{
				easy = easy->next;
				speedy = speedy->next;
			}
			return (speedy);
		}
	}

	return (NULL);
}
