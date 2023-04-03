#include "lists.h"

/**
 * free_listint - free linked list
 * @head: linked list
 */
void free_listint(listint_t *head)
{
	listint_t *pt;

	if (head == NULL)
		return;

	while (head)
	{
		pt = head;
		head = head->next;
		free(pt);
	}
}
