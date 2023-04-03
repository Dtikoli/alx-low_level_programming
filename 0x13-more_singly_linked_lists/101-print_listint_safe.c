#include "lists.h"

/**
 * print_listint_safe - Print a linked lists with memory addresses
 * @head: linked list
 * Description: Go through the list only once.
 * Return: number of nodes in list. If fails, exit with status 98.
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t c;
	const listint_t *tmp;

	if (head == NULL)
		exit(98);

	for (c = 0; head; c++)
	{
		tmp = head;
		head = head->next;
		printf("[%p] %d\n", (void *)tmp, tmp->n);

		if (tmp < head)
		{
			printf("-> [%p] %d\n", (void *)head, head->n);
			break;
		}
	}

	return (c);
}

