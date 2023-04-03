#include "lists.h"

/**
 * get_nodeint_at_index - returns nth node of listint_t linked list
 * @head: linked list
 * @index: index of nth node (starting from 0)
 * Return: nth node, or NULL if it does not exist
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{

	unsigned int c;

	for (c = 0; head && c < index; c++) /* iterate through list to tail */
		head = head->next;

	return (head);
}
