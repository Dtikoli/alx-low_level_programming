#include "main.h"

/**
 * _strchr - locate 1st occurrence of char in string and returns pointer there
 * @s: string to search
 * @c: target characer
 * Return: pointer to that character in string
 */
char *_strchr(char *s, char c)
{
	int i = 0;

	for (; s[i] && s[i] != c; i++) /* find match */
		;
	if (s[i] == c) /* if match, assign to address */
		return (s + i);
	else
		return ('/0');
}
