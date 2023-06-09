#include "hash_tables.h"

/**
 * hash_table_delete - Deletes a hash table.
 * @ht: A pointer to a hash table.
 */
void hash_table_delete(hash_table_t *ht)
{
	hash_table_t *current;
	hash_node_t *hnode, *temp;
	unsigned long int idx;

	current = ht;
	for (idx = 0; idx < ht->size; idx++)
	{
		if (ht->array[idx])
		{
			hnode = ht->array[idx];
			while (hnode)
			{
				temp = hnode->next;
				free(hnode->key);
				free(hnode->value);
				free(hnode);
				hnode = temp;
			}
		}
	}
	free(current->array);
	free(current);
}
