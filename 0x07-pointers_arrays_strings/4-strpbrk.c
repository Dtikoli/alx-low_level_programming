#include "main.h"

/**
 * _strpbrk - return pointer to byte in s that matches a byte in accept
 * @s: string to search
 * @accept: target matches
 * Return: pointer to index of string at first occurence
 */
char *_strpbrk(char *s, char *accept)
{
	int i, j;

	for (i = 0; s[i]; i++)
	{
		for (j = 0; accept[j] && s[i] != accept[j]; j++)
			;
		if (s[i] == accept[j])
			return (&s[i]);
	}
	return (0);
}
