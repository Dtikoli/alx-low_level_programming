#include "hash_tables.h"

/**
 * hash_table_get - Retrieves a value associated with a key.
 * @ht: A pointer to the hash table.
 * @key: key to get the value for.
 * Return: value associated with key, otherwise NULL.
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	hash_node_t *hnode;
	unsigned long int idx;

	if (ht == NULL || key == NULL || *key == '\0')
		return (NULL);

	idx = key_index((const unsigned char *)key, ht->size);
	if (idx >= ht->size)
		return (NULL);

	hnode = ht->array[idx];
	while (hnode && strcmp(hnode->key, key) != 0)
		hnode = hnode->next;

	if (hnode)
		return (hnode->value);

	else
		return (NULL);
}
