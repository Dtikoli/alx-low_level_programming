#include "lists.h"

/**
 * free_listint2 - frees a linked list and set the head to NULL
 * @head: head of the linked list
 */
void free_listint2(listint_t **head)
{
	listint_t *tmp;

	if (head == NULL)
		return;

	while (*head)
	{
		tmp = *head;
		*head = tmp->next;
		free(tmp);
	}
}
