#include "main.h"
#include <stdlib.h>

/**
 * free_words - frees a 2D array of words.
 * @grid: multidimensional array of char.
 * @n: number of the words making the array.
 * Return: no return
 */
void free_words(char **grid, int n)
{
	int i;

	if (grid != NULL && n != 0)
	{
		for (i = 0; i < n; i++)
			free(grid[i]);
		free(grid);
	}
}

/**
 * strtow - splits a string into words.
 * @str: string.
 * Return: pointer of an array of integers
 */
char **strtow(char *str)
{
	char **p;
	int c, i, j;
	int k = 0;
	int n = 0;

	if (str == NULL || *str == '\0')
		return (NULL);
	for (c = 0; str[c]; c++)
		if (str[c] != ' ' && (str[c + 1] == ' ' || str[c + 1] == '\0'))
			n++;
	p = malloc(sizeof(*p) * (n + 1));
	if (p == NULL || n == 0)
	{
		free(p);
		return (NULL);
	}
	for (i = 0; i < n; i++)
	{
		for (c = k; str[c]; c++)
		{
			if (str[c] == ' ')
				k++;
			if (str[c] != ' ' && (str[c + 1] == ' ' || str[c + 1] == '\0'))
			{
				p[i] = malloc(sizeof(**p) * (c - k + 2));
				if (p[i] == NULL)
				{
					free_words(p, i);
					return (NULL);
				}
				break;
			}
		}
		for (j = 0; k <= c; k++, j++)
			p[i][j] = str[k];
		p[i][j] = '\0';
	}
	p[i] = NULL;
	return (p);
}

