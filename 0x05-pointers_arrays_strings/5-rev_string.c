#include "main.h"

/**
 * rev_string - reverse a string
 * @s: char array string type
 */

void rev_string(char *s)
{
	int i, c;
	char h;

	for (i = 0; s[i]; i++)
		;

	c = 0;
	while (i > c)
	{
		h = s[--i];
		s[i] = s[c];
		s[c++] = h;
	}
}

