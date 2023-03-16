#include "main.h"
#include <stdlib.h>

/**
  * _calloc - allocates memory for an array
  * @nmemb: number of elements in array
  * @size: byte of array type
  * Return: a pointer to the allocated memory
  */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	char *p;
	unsigned int i;

	if (nmemb <= 0 || size <= 0)
		return (NULL);
	p = malloc(nmemb * size);
	if (p == NULL)
	{
		free(p);
		return (NULL);
	}
	for (i = 0; i < nmemb; i++)
		p[i] = 0;
	return (p);
}
