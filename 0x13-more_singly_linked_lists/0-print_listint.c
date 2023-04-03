#include "lists.h"

/**
  * print_listint - prints the nodes of a linked list
  * @h: linked list
  * Return: the number of nodes
  */
size_t print_listint(const listint_t *h)
{
	size_t c = 0; /* number of nodes */

	while (h)
	{
		printf("%d\n", h->n);
		c++;
		h = h->next;
	}
	return (c);
}
