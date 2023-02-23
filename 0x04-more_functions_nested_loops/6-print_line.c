#include "main.h"

/**
 * print_line - print the character "_" n times to draw a line
 * @n: number of characters to draw
 */
void print_line(int n)
{
	int t;

	for (t = n; t >= 1; t--)
		_putchar('_');

	_putchar('\n');
}
