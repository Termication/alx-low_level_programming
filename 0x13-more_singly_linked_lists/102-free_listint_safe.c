#include "lists.h"

/**
 * free_listint_safe - Safely frees a
 * linked list to avoid loops.
 * @h: Pointer to the first node in the linked list.
 *
 * Description:
 *	This function safely frees a linked list,
 *	avoiding potential loops
 *	by comparing memory addresses of consecutive nodes.
 *	If a loop is detected,
 *	it terminates the loop to avoid infinite freeing.
 *
 * Return: Number of elements freed.
 */
size_t free_listint_safe(listint_t **h)
{
	size_t count = 0;
	int difference;
	listint_t *temporary;

	if (!h || !*h)
		return (0);
	while (*h)
	{
		difference = *h - (*h)->next;
		if (difference > 0)
		{
			temporary = (*h)->next;
			free(*h);
			*h = temporary;
			count++;
		}
		else
		{
			free(*h);
			*h = NULL;
			count++;
			break;
		}
	}
	*h = NULL;
	return (count);
}
