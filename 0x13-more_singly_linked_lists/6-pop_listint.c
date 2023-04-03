#include "lists.h"

/**
 * pop_listint - deletes the head node of a linked list
 * @head: head node of linked list
 * Return: head nodes data (n)
 */
int pop_listint(listint_t **head)
{
	int hdata;
	listint_t *tmp;

	if (*head == NULL)
		return (0);

	tmp = *head;
	hdata = tmp->n;
	*head = tmp->next;
	free(tmp);

	return (hdata);
}
