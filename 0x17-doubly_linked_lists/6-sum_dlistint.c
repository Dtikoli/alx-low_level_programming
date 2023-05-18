#include "lists.h"

/**
 * sum_dlistint - returns the sum of all the data (n) of a list
 * @head: pointer to the head of the list
 * Return: sum of data values
 */
int sum_dlistint(dlistint_t *head)
{
	dlistint_t *current = head;
	int sum;

	for (sum = 0; current; current = current->next)
		sum += current->n;

	return (sum);
}
