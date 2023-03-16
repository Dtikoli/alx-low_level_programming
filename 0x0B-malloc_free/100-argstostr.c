#include "main.h"
#include <stdlib.h>

/**
 * argstostr - concatenates all the arguments of a program.
 * @ac: argument count.
 * @av: argument vector.
 * Return: pointer of an array of char
 */
char *argstostr(int ac, char **av)
{
	char *str;
	int i, j;
	int k = 0;
	int len = 0;

	if (ac == 0 || av == NULL)
		return (NULL);

	for (i = 0; i < ac; i++)
	{
		for (j = 0; av[i][j]; j++)
			len++;
		len++; /* account for null term. */
	}

	str = malloc((len + 1) * sizeof(*str));

	if (str == NULL)
	{
		free(str);
		return (NULL);
	}

	for (i =  0; i < ac; i++)
	{
		for (j = 0; av[i][j]; j++)
		{
			str[k] = av[i][j];
			k++;
		}
		str[k] = '\n'; /* introduce a new line at the null term. */
		k++; /* increase k after every new line */
	}
	str[k] = '\0';

	return (str);
}
