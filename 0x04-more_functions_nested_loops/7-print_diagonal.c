#include "main.h"

/**
 * print_diagonal - print character "\" n times
 * @n: number of characters to draw
 */
void print_diagonal(int n)
{
	int d;
	int s;

	if (n > 0)
	{
		for (d = 0; d < n; d++)
		{
			for (s = 0; s < d; s++)
				_putchar(' ');
			_putchar(92);
			_putchar('\n');
		}
	}
	else
		_putchar('\n');
}
