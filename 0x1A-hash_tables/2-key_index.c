#include "hash_tables.h"

/**
 * key_index - Get the index at which a key/value pair should be
 *             stored in array of a hash table using djbe algorithm.
 * @key: key to get the index for.
 * @size: Size of the hash table array.
 * Return: The index of the key.
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	return (hash_djb2(key) % size);
}
