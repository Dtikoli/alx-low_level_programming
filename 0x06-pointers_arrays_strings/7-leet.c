#include "main.h"

/**
 * leet - encode string into 1337 leet
 * @s: string to manipulate
 * Return: string
 */
char *leet(char *s)
{

	char decode[]= "aAeEoOtTlL";
	char encode[] = "4433007711";

	int i, j;

	for (j = 0; s[j]; j++)
	{
		for (i = 0; decode[i]; i++)
		{
			if (s[j] == decode[i])
				s[j] = encode[i];
		}
	}
	return (s);
}

