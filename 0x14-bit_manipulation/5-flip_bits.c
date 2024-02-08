#include "main.h"

/**
 * flip_bits - Calculates the number of bits that need to be flipped to
 * convert one number to another.
 * @n: The first number.
 * @m: The second number.
 *
 * Return: The number of bits that need to be flipped.
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int xor_result = n ^ m;
	unsigned long int bit_difference;
	int bit_count = 0;
	int shift_count;

	for (shift_count = 63; shift_count >= 0; shift_count--)
	{
		bit_difference = xor_result >> shift_count;
		if (bit_difference & 1)
			bit_count++;
	}

	return (bit_count);
}
