#include "main.h"

/**
 * get_endianness - Determines the endianness of the system.
 *
 * Return: 0 if big endian, 1 if little endian.
 */
int get_endianness(void)
{
	int test_value = 1;
	char *test_bytes = (char *)&test_value;

	return (*test_bytes);
}
