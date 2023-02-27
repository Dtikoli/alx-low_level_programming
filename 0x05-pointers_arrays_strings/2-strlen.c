#include "main.h"

/**
 * _strlen - return the length of the string
 * @s: char type pointer
 * Return: length of string
 */

int _strlen(char *s)
{
	int ch;

	for (ch = 0; s[ch]; ch++)
		;

	return (ch);
}
