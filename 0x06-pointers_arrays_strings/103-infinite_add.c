#include "main.h"
#include <stdio.h>

/**
 * infinite_add - adds two numbers
 * @n1: number one.
 * @n2: number two.
 * @r: buffer that the function will use to store the result.
 * @size_r: buffer size:
 * Return: the pointer to dest.
 */
char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
	int len1 = 0, len2 = 0, max_len;
	int i = 0, dgt1, dgt2, sum, carry = 0;

	while (n1[len1])
		len1++;
	while (n2[len2])
		len2++;
	max_len = len1 >= len2 ? len1 : len2;

	if (max_len + 1 > size_r)
		return (0);
	/* Add the digits from right to left */
	for (i = 0; i < max_len; i++)
	{
		dgt1 = (i < len1) ? n1[len1 - 1 - i] - '0' : 0;
		dgt2 = (i < len2) ? n2[len2 - 1 - i] - '0' : 0;
		sum = dgt1 + dgt2 + carry;

		if (sum >= 10)
		{
			carry = 1;
			sum -= 10;
		}
		else
			carry = 0;
		r[max_len - 1 - i] = sum + '0';
	}
	/* Add the last carry if there is one */
	if (carry)
	{
		if (max_len + 1 > size_r)
			return (0);
		r[0] = carry + '0';
		r[max_len] = '\0';
		return (&r[0]);
	}
	/* Add the terminating null character and return the result */
	r[max_len] = '\0';

	return (&r[0]);
}
