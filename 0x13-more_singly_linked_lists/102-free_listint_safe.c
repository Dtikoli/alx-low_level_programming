#include "lists.h"

/**
 * free_listint_safe - free a linked list and set the head to null
 * @h: head pointer to linked list
 * Description: This function should work for circular lists
 * Only loop through the list once
 * Return: size of the list that was free'd
 */
size_t free_listint_safe(listint_t **h)
{
	listint_t *tmp, *current;
	size_t c;

	if (head == NULL || *head == NULL)
		return (0);

	current = *h;
	for (c = 0; current; c++)
	{
		tmp = current;
		current = current->next;
		free(tmp);

		if (tmp < current)
		{
			free(current);
			break;
		}
	}
	*h = NULL;

	return (c);
}

