#include "lists.h"

/**
  * listint_len - returns the number of elements of a linked list
  * @h: linked list
  * Return: number of nodes
  */
size_t listint_len(const listint_t *h)
{
	size_t c = 0; /* number of nodes */

	while (h)
	{
		c++;
		h = h->next;
	}
	return (c);
}

