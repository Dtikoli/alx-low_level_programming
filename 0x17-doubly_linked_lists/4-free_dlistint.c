#include "lists.h"

/**
 * free_dlistint - frees a list
 * @head: pointer to the head of the list
 * Return: Nothing
 */
void free_dlistint(dlistint_t *head)
{
	dlistint_t *current;

	while (head)
	{
		current = head;
		head = head->next;
		free(current);
	}
}
