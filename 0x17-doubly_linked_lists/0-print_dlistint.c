#include "lists.h"

/**
 * print_dlistint - Print all the value data of list
 * @h: head pointer in doubly linked list
 * Return: Number of nodes
 */
size_t print_dlistint(const dlistint_t *h)
{
	const dlistint_t *current = h;
	size_t size;

	for (size = 0; current; current = current->next)
	{
		printf("%d\n", current->n);
		size++;
	}

	return (size);
}
