#include "lists.h"

/**
 * _loop_listint_len - finds the length of a loop in a linked list
 * @head: linked list
 * Return: the number of nodes in the loop, or 0 if there is no loop
 */
size_t _loop_listint_len(const listint_t *head)
{
	const listint_t *lag, *lead;
	size_t c = 0;

	/* If the list is empty or has only one node, there is no loop */
	if (head == NULL || head->next == NULL)
		return (0);

	lag = lead = head;

	/* Floyd's cycle-finding algorithm */
	while (lag && lead && lead->next)
	{
		lag = lag->next;
		lead = lead->next->next;

		c++;

		if (lag == lead)
		{
			lag = head;
			while (lag != lead)
			{
				c++;
				lag = lag->next;
				lead = lead->next;
			}


			return (c);
		}

	}

	return (0);
}

/**
 * print_listint_safe - Prints the elements in a linked list safely.
 * @head: linked list.
 * Return: The number of nodes in the list.
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t c, i;

	c = _loop_listint_len(head);

	if (!c) /* same as if c = 0 */
	{
		for (; head; c++)
		{
			printf("[%p] %d\n", (void *) head, head->n);
			head = head->next;
		}
	}
	else
	{
		for (i = 0; i < c; i++)
		{
			printf("[%p] %d\n", (void *) head, head->n);
			head = head->next;
		}
		printf("-> [%p] %d\n", (void *) head, head->n);
	}

	return (c);
}

