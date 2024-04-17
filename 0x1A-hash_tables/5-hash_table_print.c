#include "./hash_tables.h"

/**
 * hash_table_print - Prints a hash table
 * @ht: Pointer to the hash table
 *
 * Description: This function prints a hash table in the following format:
 * {key: value, key: value, ...}
 * If the hash table is NULL, nothing is printed.
 */
void hash_table_print(const hash_table_t *ht)
{
	hash_node_t *current_node;
	unsigned long int index;
	unsigned char is_comma_needed = 0;

	if (ht == NULL)
		return;

	printf("{");
	for (index = 0; index < ht->size; index++)
	{
		if (ht->array[index] != NULL)
		{
			if (is_comma_needed == 1)
				printf(", ");

			current_node = ht->array[index];
			while (current_node != NULL)
			{
				printf("'%s': '%s'", current_node->key, current_node->value);
				current_node = current_node->next;
				if (current_node != NULL)
					printf(", ");
			}
			is_comma_needed = 1;
		}
	}
	printf("}\n");
}
