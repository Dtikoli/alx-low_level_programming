#include <stdlib.h>
#include "main.h"

/**
 * string_nconcat -  concatenate two strings
 * @s1: destination string
 * @s2: source string
 * @n: number of bytes from source string to concatenate
 * Return: pointer to newly allocated memory containing s1
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	char *p;
	unsigned int i, j;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";
	for (i = 0; s1[i]; i++)
		;
	for (j = 0; s2[j]; j++)
		;
	if (n < j)
		j = n;
	p = malloc(sizeof(*p) * (i + j + 1));
	if (p == NULL)
	{	free(p);
		return (NULL);
	}
	for (i = 0; s1[i]; i++)
		p[i] = s1[i];
	for (j = 0; s2[j] && j < n; j++)
		p[i + j] = s2[j];
	p[i + j] = '\0';
	return (p);
}
