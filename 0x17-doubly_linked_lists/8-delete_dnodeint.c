#include "lists.h"

/**
 * get_dnodeint_at_index - returns the nth node of a linked list
 * @head: pointer to the head of the list
 * @index: index of the node to return
 * Return: address of the nth node, or NULL if the node doesn't exist
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	dlistint_t *current = head;
	unsigned int i;

	for (i = 0; current && i < index; i++)
		current = current->next;

	return (current);
}

/**
 * delete_dnodeint_at_index - deletes the node at index of a list
 * @head: pointer to the head of the list
 * @index: index of the node to delete
 * Return: 1 if it succeeded, -1 if it failed
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *tmp;

	if (!head || !*head)
		return (-1);

	tmp = get_dnodeint_at_index(*head, index);
	if (!tmp)
		return (-1);

	if (tmp->prev)
		tmp->prev->next = tmp->next;
	else
		*head = tmp->next;

	if (tmp->next)
		tmp->next->prev = tmp->prev;
	free(tmp);

	return (1);
}

