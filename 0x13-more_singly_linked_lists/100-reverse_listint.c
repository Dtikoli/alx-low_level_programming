#include "lists.h"

/**
 * reverse_listint - reverses a linked list
 * @head: head pointer of linked list
 * Return: pointer to first node of the reversed list
 */
listint_t *reverse_listint(listint_t **head)
{
	listint_t *prev, *nex;

	/* account for no ptr and empty list */
	if (*head == NULL || head == NULL)
		return (NULL);

	/* iterate through list to reverse linking */
	prev = NULL;
	nex = NULL;
	while (*head)
	{
		nex = (*head)->next; /* keep track of next node to move to */
		(*head)->next = prev; /* link current node's ptr to prev node */
		prev = *head; /* update previous node to be current node */
		*head = nex; /* move current node to next node */
	}
	*head = prev; /* unlink last element from null and point backwards */

	return (*head);
}

