#include <string.h>
#include <stdlib.h>
#include "hash_tables.h"

/**
 * create_node - Allocates and initializes a new hash node
 * @key: The key string
 * @value: The value string
 *
 * Return: Pointer to the new node, or NULL on failure
 */
static hash_node_t *create_node(const char *key, const char *value)
{
	hash_node_t *node;

	node = malloc(sizeof(hash_node_t));
	if (node == NULL)
		return (NULL);

	node->key = strdup(key);
	if (node->key == NULL)
	{
		free(node);
		return (NULL);
	}

	node->value = strdup(value);
	if (node->value == NULL)
	{
		free(node->key);
		free(node);
		return (NULL);
	}

	node->next = NULL;
	return (node);
}

/**
 * hash_table_set - Adds or updates a key/value pair in a hash table
 * @ht: The hash table
 * @key: The key string (cannot be empty)
 * @value: The value string to associate with the key
 *
 * Return: 1 on success, 0 on failure
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	hash_node_t *node, *cursor;
	unsigned long int index;

	if (ht == NULL || key == NULL || *key == '\0')
		return (0);

	index = key_index((const unsigned char *)key, ht->size);
	cursor = ht->array[index];
	while (cursor != NULL)
	{
		if (strcmp(cursor->key, key) == 0)
		{
			free(cursor->value);
			cursor->value = strdup(value);
			return (cursor->value != NULL ? 1 : 0);
		}
		cursor = cursor->next;
	}

	node = create_node(key, value);
	if (node == NULL)
		return (0);

	node->next = ht->array[index];
	ht->array[index] = node;
	return (1);
}
