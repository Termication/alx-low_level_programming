#include "main.h"

/**
 * _calculate_power - Calculates an integer raised to a power.
 * @base: The base number.
 * @exponent: The exponent.
 *
 * Return: The result of base raised to the exponent.
 */
unsigned long int _calculate_power(unsigned int base, unsigned int exponent)
{
	unsigned long int result = 1;
	unsigned int index;

	for (index = 1; index <= exponent; index++)
	{
		result *= base;
	}
	return (result);
}

/**
 * print_binary - Prints the binary representation of an unsigned long integer.
 * @n: The number to be converted to binary.
 *
 * Return: void (no return value)
 */
void print_binary(unsigned long int n)
{
	unsigned long int bit_mask, current_bit;
	char leading_zero_skipped = 0;

	bit_mask = _calculate_power(2, sizeof(unsigned long int) * 8 - 1);

	while (bit_mask != 0)
	{
		current_bit = n & bit_mask;

		if (current_bit == bit_mask)
		{
			leading_zero_skipped = 1;
			_putchar('1');
		}
		else if (leading_zero_skipped || bit_mask == 1)
		{
			_putchar('0');
		}
		bit_mask >>= 1;
	}
}
