#include "main.h"
#include <stdlib.h>

/**
  * alloc_grid - returns a pointer to a 2D array of integers
  * @width: columns of the array
  * @height: rows fo the array
  * Return: a pointer to to the 2D array, NULL on failure
  */
int **alloc_grid(int width, int height)
{
	int i, j;
	int **p;

	if (width <= 0 || height <= 0)
		return (NULL);
	p = malloc(sizeof(*p) * height);
	if (p == NULL)
		return (NULL);
	for (i = 0; i < height; i++)
	{
		p[i] = malloc(sizeof(*p) * width);
		if (p[i] == 0)
		{
			for (i = 0; i < height; i++)
				free(p[i]);
			free(p);
			return (NULL);
		}
		for (j = 0; j < width; j++)
			p[i][j] = 0;
	}
	return (p);
}
