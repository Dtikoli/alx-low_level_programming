#include "lists.h"

/**
  * add_nodeint - add nodes at the beginning of a linked list
  * @head: head of the linked list
  * @n: interger to store in the list
  * Return: the address of the new element of NULL, if it fails
  */
listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *new;

	new = malloc(sizeof(listint_t));
	if (new == NULL)
	{
		free(new);
		return (NULL);
	}

	new->n = n;
	new->next = *head;
	*head = new;

	return (*head);
}
