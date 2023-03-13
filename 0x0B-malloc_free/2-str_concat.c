#include "main.h"
#include <stdlib.h>

/**
  * str_concat - concatenates two strings.
  * @s1: destination string
  * @s2: source string
  * Return: a poiner to s1
  */
char *str_concat(char *s1, char *s2)
{
	int i, j, m, k;
	char *p;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";
	for (i = 0; s1[i]; i++)
		;
	for (j = 0; s2[j]; j++)
		;
	p = malloc(sizeof(*p) * (i + j + 1));
	if (p == NULL)
		return (NULL);
	for (m = 0; s1[m]; m++)
		p[m] = s1[m];
	for (k = 0; k <= j; k++)
		p[m + k] = s2[k];
	return (p);
}
