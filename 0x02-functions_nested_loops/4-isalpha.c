#include "main.h"

/**
 * _isalpha - checks for alphabet character
 * @c: The ASCII code character to check
 * Return: 1 if lower or uppercase, 0 if not alphabet character
 */
int _isalpha(int ch)
{
	if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
	{
		return (1);
	}
	else
	{
		return (0);
	}
	_putchar('\n');
}
