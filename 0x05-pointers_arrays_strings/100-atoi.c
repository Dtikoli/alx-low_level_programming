#include "main.h"

/**
 * _atoi - convert a string to an integer
 * @s: string to convert
 * Return: integer
 */
int _atoi(char *s)
{
	unsigned int num = 0;
	int sign = 1;

	while (*s)
	{
		if (*s == '-')
			sign *= -1;
		else if (*s >= 48 && *s <= 57)
			num = num * 10 + (*s - 48);
		if (s[i + 1] < 48 || s[i + 1] > 57)
			break;
		s++;
	}
	return (num * sign);
}
