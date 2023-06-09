#include "./hash_tables.h"

/**
 * hash_table_print - Prints a a key/value pair in order of appearance.
 * @ht: A pointer to the hash table.
 */
void hash_table_print(const hash_table_t *ht)
{
	hash_node_t *hnode;
	unsigned long int idx;
	unsigned char cflag = 0;

	if (ht == NULL)
		return;

	printf("{");
	for (idx = 0; idx < ht->size; idx++)
	{
		if (ht->array[idx] != NULL)
		{
			if (cflag == 1)
				printf(", ");

			hnode = ht->array[idx];
			while (hnode)
			{
				printf("'%s': '%s'", hnode->key, hnode->value);
				hnode = hnode->next;
				if (hnode)
					printf(", ");
			}
			cflag = 1;
		}
	}
	printf("}\n");
}
