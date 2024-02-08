#include "main.h"

/**
 * binary_to_uint - Converts a binary string to an unsigned integer.
 * @b: Pointer to a null-terminated string containing a binary number.
 *
 * Return: The converted unsigned integer, or 0 if an error occurs.
 */
unsigned int binary_to_uint(const char *b)
{
	int index;
	unsigned int decimal_value = 0;

	if (!b)
	{
		return (0);
	}

	for (index = 0; b[index] != '\0'; index++)
	{
		if (b[index] != '0' && b[index] != '1')
		{
			return (0);
		}
	}

	for (index = 0; b[index] != '\0'; index++)
	{
		decimal_value <<= 1;
		if (b[index] == '1')
		{
			decimal_value += 1;
		}
	}

	return (decimal_value);
}
