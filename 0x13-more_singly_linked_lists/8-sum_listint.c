#include "lists.h"

/**
 * sum_listint - returns the sum of the data (n) of a linked list.
 * @head: a linked  list.
 * Return: sum of the data (n) of all elements.
 */
int sum_listint(listint_t *head)
{
	int sum = 0;

	while (head)
	{
		sum += head->n;
		head = head->next;
	}

	return (sum);
}
