#include "lists.h"

/**
 * loop_listint_len - finds the length of a loop in a linked list
 * @head: linked list
 * Return: the number of nodes in the loop, or 0 if there is no loop
 */
size_t loop_listint_len(listint_t *head)
{
	listint_t *lag, *lead;
	size_t c = 1;

	/* If the list is empty or has only one node, there is no loop */
	if (head == NULL || head->next == NULL)
		return (0);

	lag = lead = head;

	/* Floyd's cycle-finding algorithm */
	while (lag && lead && lead->next)
	{
		lag = lag->next;
		lead = lead->next->next;
		if (lag == lead)
		{
			lag = head;
			while (lag != lead)
			{
				c++;
				lag = lag->next;
				lead = lead->next;
			}

			lag = lag->next;
			while (lag != lead)
			{
				c++;
				lag = lag->next;
			}

			return (c);
		}

	}

	return (0);
}

/**
 * free_listint_safe - frees a linked list with a loop safely.
 * @h: head pointer of the linked list.
 * Return: The number of nodes in the list.
 */
size_t free_listint_safe(listint_t **h)
{
	listint_t *tmp;
	size_t c, i;

	c = loop_listint_len(*h);

	if (!c) /* same as if c = 0 */
	{
		for (; *h; c++)
		{
			tmp = *h;
			*h = (*h)->next;
			free(tmp);
		}
	}
	else
	{
		for (i = 0; i < c; i++)
		{
			tmp = *h;
			*h = (*h)->next;
			free(tmp);
		}

		*h = NULL;
	}

	return (c);
}


