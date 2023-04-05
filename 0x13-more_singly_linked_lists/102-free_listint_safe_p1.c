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
 * free_listint_safe - frees a linked list.
 * @h: head pointer of linked list.
 * Return: number of nodes in the list.
 */
size_t free_listint_safe(listint_t **h)
{
	size_t c;
	listp_t *hpt, *prev, *nex;
	listint_t *current;

	hpt = NULL;
	for (c = 0; *h; c++)
	{
		prev = malloc(sizeof(listp_t));

		if (prev == NULL)
			exit(98);

		prev->p = (void *)*h;
		prev->next = hpt;
		hpt = prev;

		nex = hpt;

		while (nex->next)
		{
			nex = nex->next;
			if (*h == nex->p)
			{
				*h = NULL;
				free_listp(&hpt);
				return (c);
			}
		}

		current = *h;
		*h = (*h)->next;
		free(current);
	}

	*h = NULL;
	free_listp(&hpt);
	return (c);
}

