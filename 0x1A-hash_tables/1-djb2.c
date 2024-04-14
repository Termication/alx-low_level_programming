#include "hash_tables.h"

/**
 * hash_djb2 - Hash function using the djb2 algorithm
 * @str: The string to be hashed
 *
 * Return: The hash value
 */
unsigned long int hash_djb2(const unsigned char *str)
{
	unsigned long int hash_value;
	int char_count;

	hash_value = 5381;
	while ((char_count = *str++))
		hash_value = ((hash_value << 5) + hash_value) + char_count; /* hash * 33 + char_count */

	return (hash_value);
}
