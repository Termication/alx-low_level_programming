#include "hash_tables.h"

/**
 * hash_table_set - Adds an element to the hash table
 * @ht: The hash table to add or update the key/value to
 * @key: The key, cannot be an empty string
 * @value: The value associated with the key
 *
 * Return: 1 if success, 0 otherwise
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	hash_node_t *new_node;
	char *value_duplicate;
	unsigned long int index, i;

	if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
		return (0);

	value_duplicate = strdup(value);
	if (value_duplicate == NULL)
		return (0);

	index = key_index((const unsigned char *)key, ht->size);
	for (i = index; ht->array[i]; i++)
	{
		if (strcmp(ht->array[i]->key, key) == 0)
		{
			free(ht->array[i]->value);
			ht->array[i]->value = value_duplicate;
			return (1);
		}
	}

	new_node = malloc(sizeof(hash_node_t));
	if (new_node == NULL)
	{
		free(value_duplicate);
		return (0);
	}
	new_node->key = strdup(key);
	if (new_node->key == NULL)
	{
		free(new_node);
		return (0);
	}
	new_node->value = value_duplicate;
	new_node->next = ht->array[index];
	ht->array[index] = new_node;

	return (1);
}
