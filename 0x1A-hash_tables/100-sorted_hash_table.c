#include "hash_tables.h"

shash_table_t *shash_table_create(unsigned long int size);
int shash_table_set(shash_table_t *ht, const char *key, const char *value);
char *shash_table_get(const shash_table_t *ht, const char *key);
void shash_table_print(const shash_table_t *ht);
void shash_table_print_rev(const shash_table_t *ht);
void shash_table_delete(shash_table_t *ht);

/**
 * shash_table_create - Creates a sorted hash table.
 * @size: The size of new sorted hash table.
 * Return: pointer to the sorted hash table on success, otherwise NULL.
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *new_ht;
	unsigned long int idx;

	new_ht = malloc(sizeof(shash_table_t));
	if (!new_ht)
		return (NULL);

	new_ht->size = size;
	new_ht->array = malloc(sizeof(shash_node_t *) * size);
	if (!new_ht->array)
		return (NULL);
	for (idx = 0; idx < size; idx++)
		new_ht->array[idx] = NULL;
	new_ht->shead = NULL;
	new_ht->stail = NULL;

	return (new_ht);
}

/**
 * shash_table_set - Adds an element to a sorted hash table.
 * @ht: A pointer to the sorted hash table.
 * @key: key to add, cannot be an empty string.
 * @value: The value associated with key.
 * Return: 1 on success, otherwise 0.
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	shash_node_t *new_node, *temp;
	char *val_copy;
	unsigned long int idx;

	if (!ht || !key || *key == '\0' || !value)
		return (0);

	val_copy = strdup(value);
	if (!val_copy)
		return (0);

	idx = key_index((const unsigned char *)key, ht->size);
	temp = ht->shead;
	while (temp)
	{
		if (strcmp(temp->key, key) == 0)
		{
			temp->value = val_copy;
			return (1);
		}
		temp = temp->snext;
	}

	new_node = malloc(sizeof(shash_node_t));
	if (!new_node)
	{
		free(val_copy);
		return (0);
	}
	new_node->key = strdup(key);
	if (!new_node->key)
	{
		free(val_copy);
		free(new_node);
		return (0);
	}
	new_node->value = val_copy;
	new_node->next = ht->array[idx];
	ht->array[idx] = new_node;

	if (!ht->shead)
	{
		new_node->sprev = NULL;
		new_node->snext = NULL;
		ht->shead = new_node;
		ht->stail = new_node;
	}
	else if (strcmp(ht->shead->key, key) > 0)
	{
		new_node->sprev = NULL;
		new_node->snext = ht->shead;
		ht->shead->sprev = new_node;
		ht->shead = new_node;
	}
	else
	{
		temp = ht->shead;
		while (temp->snext && strcmp(temp->snext->key, key) < 0)
			temp = temp->snext;
		new_node->sprev = temp;
		new_node->snext = temp->snext;
		if (temp->snext == NULL)
			ht->stail = new_node;
		else
			temp->snext->sprev = new_node;
		temp->snext = new_node;
	}

	return (1);
}

/**
 * shash_table_get - Retrieves a value associated with a key.
 * @ht: A pointer to the sorted hash table.
 * @key: The key to get the value of.
 * Return: the value associated with the key, otherwise NULL.
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	shash_node_t *hnode;
	unsigned long int idx;

	if (!ht || !key || *key == '\0')
		return (NULL);

	idx = key_index((const unsigned char *)key, ht->size);
	if (idx >= ht->size)
		return (NULL);

	hnode = ht->shead;
	while (hnode && strcmp(hnode->key, key) != 0)
		hnode = hnode->snext;

	if (hnode)
		return (hnode->value);

	else
		return (NULL);
}

/**
 * shash_table_print - Prints a sorted hash table in order.
 * @ht: A pointer to the sorted hash table.
 */
void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *hnode;

	if (!ht)
		return;

	hnode = ht->shead;
	printf("{");
	while (hnode)
	{
		printf("'%s': '%s'", hnode->key, hnode->value);
		hnode = hnode->snext;
		if (hnode)
			printf(", ");
	}
	printf("}\n");
}

/**
 * shash_table_print_rev - Prints a sorted hash table in reverse order.
 * @ht: A pointer to the sorted hash table.
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *hnode;

	if (!ht)
		return;

	hnode = ht->stail;
	printf("{");
	while (hnode)
	{
		printf("'%s': '%s'", hnode->key, hnode->value);
		hnode = hnode->sprev;
		if (hnode)
			printf(", ");
	}
	printf("}\n");
}

/**
 * shash_table_delete - Deletes a sorted hash table.
 * @ht: A pointer to the sorted hash table.
 */
void shash_table_delete(shash_table_t *ht)
{
	shash_table_t *current;
	shash_node_t *hnode, *temp;

	current = ht;
	if (!ht)
		return;

	hnode = ht->shead;
	while (hnode)
	{
		temp = hnode->snext;
		free(hnode->key);
		free(hnode->value);
		free(hnode);
		hnode = temp;
	}

	free(current->array);
	free(current);
}
