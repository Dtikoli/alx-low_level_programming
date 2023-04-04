#include "lists.h"

/**
 * free_listp - frees a linked list
 * @head: head pointer.
 * Return: no return.
 */
void free_listp(listp_t **head)
{
	listp_t *tmp;

	if (head == NULL)
		return;

	while (*head)
	{
		tmp = *head;
		*head = (*head)->next;
		free(tmp);
	}
}

/**
 * print_listint_safe - prints a linked list.
 * @head: linked list.
 * Return: number of nodes in the list.
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t c = 0;
	listp_t *hpt, *prev, *nex;

	hpt = NULL;
	for (c = 0; head; c++)
	{
		prev = malloc(sizeof(listp_t));

		if (prev == NULL)
			exit(98);

		prev->p = (void *)head;
		prev->next = hpt;
		hpt = prev;

		nex = hpt;

		while (nex->next)
		{
			nex = nex->next;
			if (head == nex->p)
			{
				printf("-> [%p] %d\n", (void *)head, head->n);
				free_listp(&hpt);
				return (c);
			}
		}

		printf("[%p] %d\n", (void *)head, head->n);
		head = head->next;
	}

	free_listp(&hpt);
	return (c);
}

