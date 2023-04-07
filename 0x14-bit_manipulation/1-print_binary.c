#include "main.h"

/**
 * print_binary - prints an integer in a binary format
 * @n: unsigned long integer.
 * Return: nothing.
 */
void print_binary(unsigned long int n)
{
	if (!(n > 0))
	{
		_putchar('0');
	}

	else
	{
		if (n > 1)
			print_binary(n >> 1);
		_putchar((n & 1) + '0');
	}
}
