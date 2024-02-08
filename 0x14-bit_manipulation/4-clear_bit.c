#include "main.h"
#include <stdlib.h>

/**
 * clear_bit - Sets the value of a bit at a given index within a number to 0.
 * @n: A pointer to the number to modify.
 * @index: The index of the bit to clear.
 *
 * Return: 1 if successful, or -1 if an error occurs.
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int bit_mask;

	if (index > sizeof(n) * 8)
		return (-1);

	/* Create a mask with a '0' at the specified index and '1's elsewhere */
	bit_mask = ~(1 << index);

	*n &= bit_mask;

	return (1);
}
