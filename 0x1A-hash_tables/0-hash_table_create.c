#include "hash_tables.h"

/**
 * hash_table_create - Creates a hash table.
 * @size: The size of the hash table.
 *
 * Return: A pointer to the newly created hash table, or NULL if it fails.
 */
hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *new_hash_table;
	unsigned long int index_value;

	new_hash_table = malloc(sizeof(hash_table_t));
	if (new_hash_table == NULL)
		return (NULL);

	new_hash_table->size = size;
	new_hash_table->array = malloc(size * sizeof(hash_node_t *));
	if (new_hash_table->array == NULL)
	{
		free(new_hash_table);
		return (NULL);
	}

	for (index_value = 0; index_value < size; index_value++)
		new_hash_table->array[index_value] = NULL;

	return (new_hash_table);
}
