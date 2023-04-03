#include "lists.h"

/**
 * insert_nodeint_at_index - inserts a new node at a given position.
 * @head: head of a list.
 * @idx: index for the insertion.
 * @n: node data.
 * Return: the address of the new node, or NULL if it
 * failed.
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	unsigned int c;
	listint_t *new;
	listint_t *tmp;

	tmp = *head;

	if (head == NULL)
		return (NULL);

	new = malloc(sizeof(listint_t));

	if (new == NULL)
	{
		free(new);
		return (NULL);
	}

	new->n = n;

	if (idx == 0)
	{
		new->next = *head;
		*head = new;
	}

	for (c = 1; tmp && c < idx; c++)
	{
		tmp = tmp->next;
		if (tmp == NULL)
			return (NULL);
	}

	new->next = tmp->next;
	tmp->next = new;

	return (new);
}
