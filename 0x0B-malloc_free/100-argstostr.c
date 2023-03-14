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
	int i, j, k;
	int len = 0;

	if (ac == 0 || av == NULL)
		return (NULL);

	for (i = 0; i < ac; i++)
	{
		for (j = 0; av[i][j]; j++)
			len++;
		len++;
	}

	str = malloc((len + 1) * sizeof(*str));

	if (str == NULL)
	{
		free(str);
		return (NULL);
	}

	for (i = j = k = 0; k < len; j++, k++)
	{
		if (av[i][j] == '\0')
		{
			str[k] = '\n';
			i++;
			k++;
			j = 0;
		}
		if (k < len - 1)
			str[k] = av[i][j];
	}
	str[k] = '\0';

	return (str);
}
