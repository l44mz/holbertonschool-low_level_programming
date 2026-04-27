#include <stdlib.h>
#include "hash_tables.h"

/**
 * hash_table_delete - Deletes a hash table and frees all memory
 * @ht: The hash table to delete
 *
 * Return: void
 */
void hash_table_delete(hash_table_t *ht)
{
	hash_node_t *cursor, *tmp;
	unsigned long int i;

	if (ht == NULL)
		return;

	for (i = 0; i < ht->size; i++)
	{
		cursor = ht->array[i];
		while (cursor != NULL)
		{
			tmp = cursor->next;
			free(cursor->key);
			free(cursor->value);
			free(cursor);
			cursor = tmp;
		}
	}

	free(ht->array);
	free(ht);
}
