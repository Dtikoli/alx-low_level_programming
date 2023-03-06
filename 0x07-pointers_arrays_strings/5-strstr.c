#include "main.h"
#include <stdlib.h>

/**
 * _strstr - locates a substring
 * @haystack: string to be scanned
 * @needle: string containing the sequence of characters to match
 * Return: pointer to the beginning of the located substring,
 * or NULL if the substring is not found.
 */
char *_strstr(char *haystack, char *needle)
{
	int i, j;

	/* if a byte matches first char of needle */
	/* interate through needle until match ends */
	for (i = 0; haystack[i]; i++)
	{
		for (j = 0; needle[j] && haystack[i + j]; j++)
			if (haystack[i + j] != needle[j])
				break;
		if (!needle[j]) /* if matched throughout, return to begin. of match */
			return (&haystack[i]);
	}
	return (NULL);
}
