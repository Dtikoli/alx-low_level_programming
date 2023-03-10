#include "main.h"
#include <stdlib.h>

/**
  * _strdup - returns a pointer to a new string
  * which is a duplicate of the string str
  * @str: a pointer to a string
  * Return: a pointer to a duplicate string,
  * NULL if str == NULL.
  */
char *_strdup(char *str)
{
	char *p;
	int i, j;

	if (str == NULL)
		return (NULL);
	for (j = 0; str[j]; j++)
		;
	p = malloc(sizeof(*p) * (j + 1));
	if (p == NULL)
		return (NULL);
	for (i = 0; str[i]; i++)
		p[i] = str[i];
	return (p);
}
