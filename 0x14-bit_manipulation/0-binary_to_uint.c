#include "main.h"

/**
 * binary_to_uint - convert a binary number to an unsigned integer
 * @b: string of chars
 * Return: converted decimal number or 0 if failed
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int i, num = 0;
	int len;

	if (b == NULL)
		return (0);

	/* find string length */
	for (len = 0; b[len]; len++)
	{
		if (b[len] != '0' && b[len] != '1')
			return (0);
	}

	len -= 1;

	/* iterate through string, if '1' then multiply by power of 2 */
	/* get power of 2 using binary (e.g. 1<<2 = 100 in binary = 4) */
	for (i = 0; b[i]; i++)
	{
		if (b[i] == '1')
			num += (1 * (1 << len));
		len--;
	}

	return (num);
}
