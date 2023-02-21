#include "main.h"
/**
 * _islower - Return 1 if letter is lowercase, 0 if not.
 * @c: The ASCII code character representation
 * Return: 1 if lowercase, 0 if not lowercase
 */
int _islower(int c)
{
	if (c > 96 && c <= 122)
		return (1);
	else
		return (0);
}
