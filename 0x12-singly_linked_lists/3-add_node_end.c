#include "lists.h"

/**
 * add_node_end - adds a new node at the end
 * of a list_t list.
 * @head: head of the linked list.
 * @str: string to store in the list.
 * Return: address of the head.
 */
list_t *add_node_end(list_t **head, const char *str)
{
	list_t *n, *hold; /* n is the New Node to be added */
	size_t c;

	n = malloc(sizeof(list_t));
	if (n == NULL)
		return (NULL);

	n->str = strdup(str);

	for (c = 0; str[c]; c++)
		;

	n->len = c;
	n->next = NULL;
	hold = *head;

	if (hold == NULL)
	{
		*head = n;
	}
	else
	{
		while (hold->next != NULL)
			hold = hold->next;
		hold->next = n;
	}

	return (*head);
}

