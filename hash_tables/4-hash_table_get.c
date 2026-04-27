#include <string.h>
#include "hash_tables.h"

/**
 * hash_table_get - Retrieves a value associated with a key
 * @ht: The hash table to search
 * @key: The key to look for
 *
 * Return: The value associated with the key, or NULL if not found
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	hash_node_t *cursor;
	unsigned long int index;

	if (ht == NULL || key == NULL || *key == '\0')
		return (NULL);

	index = key_index((const unsigned char *)key, ht->size);
	cursor = ht->array[index];
	while (cursor != NULL)
	{
		if (strcmp(cursor->key, key) == 0)
			return (cursor->value);
		cursor = cursor->next;
	}

	return (NULL);
}
