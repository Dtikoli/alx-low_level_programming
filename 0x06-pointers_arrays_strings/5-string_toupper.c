#include "main.h"
#define DIFF 32 /* The difference between lower and uppercase */

/**
 * string_toupper - Change all lowercase letters to uppercase
 * @c: string
 * Return: s
 */

char *string_toupper(char *s)
{
	int i;

	for (i = 0; s[i]; i++)
	{
		if (s[i] >= 'a' && s[i] <= 'z')
		{
			s[i] -= DIFF;
		}
	}
	return (s);
}

