#include "main.h"

/**
 * _strncat - concatenates two strings
 * @dest: source string;
 * serves as destination for resulting string
 * @src: source string
 * @n: number of bytes of first string  to concatenate
 * Return: pointer to resulting string dest
 */
char *_strncat(char *dest, char *src, int n)
{
	int i, j;

	for (i = 0; dest[i]; i++)
		;
	for (j = 0; src[j] && j < n; j++)
		dest[i + j] = src[j];
	dest[i + j] = '\0';
	return (dest);
}

