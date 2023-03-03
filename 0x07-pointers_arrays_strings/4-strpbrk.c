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

	for (i = 0; s[i]; i++) /*iterate through string*/
	{
		for (j = 0; accept[j] && s[i] != accept[j]; j++) /* find a match */
			;	
		if (s[i] == accept[j]) /* set pointer to first occurrenc of match */
			return (&s[i]);
	}
	return (0); /* return NULL if no matches */
}
