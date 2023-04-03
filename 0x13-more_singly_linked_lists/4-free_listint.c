#include "lists.h"

/**
 * free_listint - free linked list
 * @head: linked list
 */
void free_listint(listint_t *head)
{
	listint_t *pt;

	while (head)
	{
		pt = head;
		head = head->next;
		free(pt);
	}
}
