#include "lists.h"
/**
 * list_len - returns then number of elements in a list.
 * @h: singly linked list.
 * Return: number of elements/nodes in the list.
 */
size_t list_len(const list_t *h)
{
	size_t c; /* Number of elements */

	c = 0;
	while (h != NULL)
	{
		h = h->next;
		c++;
	}
	return (c);
}
