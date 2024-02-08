#include "main.h"

/**
 * set_bit - Sets the value of a bit within a number to 1 at a given index.
 * @n: A pointer to the number to modify.
 * @index: The index of the bit to set.
 *
 * Return: 1 if successful, or -1 if an error occurs.
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int bit_mask;

	if (index > (sizeof(unsigned long int) * 8 - 1))
		return (-1);

	bit_mask = 1 << index;
	*n |= bit_mask;

	return (1);
}
