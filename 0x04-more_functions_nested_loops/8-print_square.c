#include "main.h"

/**
 * print_square - print a square of #'s given size
 * @size: size to draw
 */

void print_square(int size)
{
	int r, c;

	if (size > 0)
	{
		for (r = size; r >= 1; r--)
		{
			for (c = size; c >= 1; c--)
			{
				_putchar('#');
			}
			_putchar('\n');
		}
	}
	else
		_putchar('\n');
}
