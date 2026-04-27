#include <stdio.h>
#include "hash_tables.h"

/**
 * hash_table_print - Prints a hash table
 * @ht: The hash table to print
 *
 * Return: void
 */
void hash_table_print(const hash_table_t *ht)
{
	hash_node_t *cursor;
	unsigned long int i;
	int printed;

	if (ht == NULL)
		return;

	printed = 0;
	printf("{");
	for (i = 0; i < ht->size; i++)
	{
		cursor = ht->array[i];
		while (cursor != NULL)
		{
			if (printed)
				printf(", ");
			printf("'%s': '%s'", cursor->key, cursor->value);
			printed = 1;
			cursor = cursor->next;
		}
	}
	printf("}\n");
}
