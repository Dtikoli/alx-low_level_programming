 #include "lists.h"

/**
  * add_nodeint_end - add nodes at the end of a linked list
  * @head: head of the linked list
  * @n: node to be added
  * Return: the address of the new element, or NULL if it failed
  */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *new, *tmp;

	new = malloc(sizeof(listint_t));
	if (new == NULL)
	{
		free(new);
		return (NULL);
	}
	new->n = n;
	new->next = NULL;
	tmp = *head;

	if (tmp == NULL)
		*head = new;
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}

	return (*head);
}
