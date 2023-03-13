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
	int i;

	if (str == NULL)
		return (NULL);
	p = malloc(sizeof(*p) * sizeof(*str));
	if (p == NULL)
		return (NULL);
	for (i = 0; str[i]; i++)
		p[i] = str[i];
	return (p);
}
