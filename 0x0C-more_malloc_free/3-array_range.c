#include "main.h"
#include <stdlib.h>

/**
  * array_range - creates an array of integers of range min to max
  * @min: value of starting element of array
  * @max: value of end element of array
  * Return: a pointer to the newly created array
  */
int *array_range(int min, int max)
{
	int *p;
	int i;

	if (min > max)
		return (NULL);
	p = malloc(sizeof(*p) * (max - min + 1));
	if (p == NULL)
	{
		free(p);
		return (NULL);
	}
	for (i = 0; i <= max - min; i++)
		p[i] = min + i;
	return (p);
}
