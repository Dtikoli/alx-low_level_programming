#include "main.h"

/**
 * print_number - prints an integer.
 * @n: input integer.
 * Return: no return.
 */
void print_number(int n)
{
	int a;	/* Absolute value of n */
	int b;	/* Base 10 convertor */
	int p;	/* Power of 10 */

	if (n < 0)
	{
		_putchar(45);
		a = n * -1;
	}
	else
	{
		a = n;
	}

	b = a;
	p = 1;

	while (b > 9)
	{
		b /= 10;
		p *= 10;
	}

	for (; p >= 1; p /= 10)
	{
		_putchar(((a / p) % 10) + 48);
	}
}
