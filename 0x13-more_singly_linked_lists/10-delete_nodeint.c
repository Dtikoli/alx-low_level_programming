#include "lists.h"

/**
 * delete_nodeint_at_index - delete a node at a given position
 * @head: head pointer of linked list
 * @index: index to delete node
 * Return: 1 if successful, or -1 if failed
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	unsigned int c;
	listint_t *tmp, *current;

	if (*head == NULL)
		return (-1);

	tmp = *head;

	if (index == 0)
	{
		*head = (*head)->next;
		free(tmp);
		return (1);
	}

	for (c = 1; tmp && c < index; c++)
		tmp = tmp->next;

	if (c != index || tmp->next == NULL)
		return (-1);

	current = tmp->next;
	tmp->next = current->next;
	free(current);

	return (1);
}
