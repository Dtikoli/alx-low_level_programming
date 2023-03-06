#include "main.h"

/**
 * rot13 - encodes a string using rot13
 * @s: string to encode
 * Return: pointer to encoded string
 */
char *rot13(char *s)
{
	int i, j;
	char decode[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char encode[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	for (i = 0; s[i]; i++)
	{
		for (j = 0; decode[j] && s[i] != decode[j]; j++)
		{
			if (s[i] == decode[j])
				s[i] = encode[j];
		}
	}
	return (s);
}
