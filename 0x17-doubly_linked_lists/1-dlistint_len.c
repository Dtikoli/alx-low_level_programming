#include "lists.h"

/**
 * dlistint_len - returns the size of a list
 * @h: head pointer in doubly linked list
 * Return: Number of nodes
 */
size_t dlistint_len(const dlistint_t *h)
{
	const dlistint_t *current = h;
	size_t size;

	for (size = 0; current; current = current->next)
		size++;

	return (size);
}
