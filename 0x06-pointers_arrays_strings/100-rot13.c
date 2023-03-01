#include "main.h"
#define ROT13 13 /* Changes the letter to the next 13th letter */

/**
 * rot13 - encodes a string using rot13
 * @s: string to encode
 * Return: pointer to encoded string
 */
char *rot13(char *s)
{
	int i;

	for (i = 0; s[i]; i++)
	{
		if ((s[i] >= 'A' && s[i] <= 'M') || (s[i] >= 'a' && s[i] <= 'm'))
			s[i] += ROT13;
		else if ((s[i] >= 'N' && s[i] <= 'Z') || (s[i] >= 'n' && s[i] <= 'z'))
			s[i] -= ROT13;
	}
	return (s);
}

