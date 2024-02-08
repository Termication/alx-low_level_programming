#include "main.h"

/**
 * get_bit - Returns the value of a bit at a given index within a number.
 * @n: The number to check.
 * @index: The index of the bit to retrieve.
 *
 * Return: The value of the bit (1 or 0), or -1 if an error occurs.
 */
int get_bit(unsigned long int n, unsigned int index)
{
	unsigned long int bit_mask;
	int bit_value;

	if (index > (sizeof(unsigned long int) * 8 - 1))
		return (-1);

	bit_mask = 1 << index;
	bit_value = (n & bit_mask) ? 1 : 0;

	return (bit_value);
}
