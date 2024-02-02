#include <stdio.h>
#include "lists.h"

/**
 * print_list - Prints the elements of a linked list
 * @h: A pointer to the list_t linked list to print
 *
 * This function traverses the given linked list
 * and prints the length and content
 * of each node. If the node's string is NULL, it prints "[0] (nil)".
 *
 * Return: The number of nodes printed in the linked list.
 */
size_t print_list(const list_t *h)
{
	size_t nodesPrinted = 0;

	while (h)
	{
		if (!h->str)
			printf("[0] (nil)\n");
		else
			printf("[%u] %s\n", h->len, h->str);

		h = h->next;
		nodesPrinted++;
	}

	return (nodesPrinted);
}
