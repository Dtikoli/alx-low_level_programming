#include "lists.h"

/**
 * find_listint_loop - find the loop in a linked list
 * @head: linked list
 * Return: address of node where loop starts
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *lag, *lead;

	lag = lead = head;
	while (lag && lead && lead->next)
	{
		lag = lag->next;
		lead = lead->next->next;

		if (lag == lead)
		{
			lag = head;
			while (lag != lead)
			{
				lag = lag->next;
				lead = lead->next;
			}

			return (lag);
		}
	}
	return (NULL);
}
