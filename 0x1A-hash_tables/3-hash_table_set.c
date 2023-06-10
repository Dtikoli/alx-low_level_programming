#include "hash_tables.h"

/**
 * hash_table_set - Adds an element to a hash table.
 * @ht: A pointer to the hash table.
 * @key: The key to add - cannot be an empty string.
 * @value: Value associated with key.
 * Return: 1 on success, otherwise 0.
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	hash_node_t *new_node;
	unsigned long int idx, i;

	if (!ht || !key || *key == '\0' || !value)
		return (0);

	idx = key_index((const unsigned char *)key, ht->size);
	for (i = idx; ht->array[i]; i++)
	{
		if (strcmp(ht->array[i]->key, key) == 0)
		{
			free(ht->array[i]->value);
			ht->array[i]->value = strdup(value);
			if (!ht->array[i]->value)
				return (0);
			return (1);
		}
	}
	new_node = malloc(sizeof(hash_node_t));
	if (!new_node)
		return (0);

	new_node->value = strdup(value);
	if (!new_node->value)
	{
		free(new_node);
		return (0);
	}
	new_node->key = strdup(key);
	if (!new_node->key)
	{
		free(new_node->value);
		free(new_node);
		return (0);
	}
	new_node->next = ht->array[idx];
	ht->array[idx] = new_node;

	return (1);
}
