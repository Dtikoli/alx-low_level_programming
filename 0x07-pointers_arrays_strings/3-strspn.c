#include "main.h"

/**
 * _strspn - return length of string that matches values consistently
 * @s: string to search
 * @accept: target matches
 * Return: number of bytes consecutively matched
 */
unsigned int _strspn(char *s, char *accept)
{
	int i, j;
	int c = 0;

	for (i = 0; s[i]; i++) /*iterate through string*/
	{
		for (j = 0; accept[j] && s[i] != accept[j]; j++) /*find a match*/
			;
		if (s[i] == accept[j]) /*record at first match*/
			c++;
		else
			return (c); /*return record if next i doesn't match*/
	}
	return (c); /* return num of all match till end */
}
