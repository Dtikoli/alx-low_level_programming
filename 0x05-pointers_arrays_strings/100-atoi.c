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
		if (num = 0 && *s == '-')
			sign *= -1;
		else if (*s >= 48 && *s <= 57)
			num = num * 10 + (*s - 48);
		else
			break;
		s++;
	}
	return (num * sign);
}
