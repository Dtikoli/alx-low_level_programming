#include "main.h"
#include <stdlib.h>

/**
  * create_array - creates an array of chars,
  * and initializes it with a specific char.
  * @size: the size of the array
  * @c: the character to initialise the array.
  * Return: 0 if size = 0, a pointer to the array,
  * or NULL if it fails.
  */
char *create_array(unsigned int size, char c)
{
	char *t;
	unsigned int i;

	if (size == 0)
		return (0);
	t = malloc(sizeof(*t) * size);
	if (t == NULL)
		return (NULL);
	for (i = 0; i < size; i++)
		t[i] = c;
	return (t);
}

