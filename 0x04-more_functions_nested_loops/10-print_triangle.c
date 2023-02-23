#include "main.h"

/**
 * print_triangle - print traingle with #'s with given size
 * @size: size of triangle to draw
 */
void print_triangle(int size)
{
	int h;	/* height of triangle */
	int w;	/* leading empty spaces at height */
	int l;	/* length of triangle */

	if (size <= 0)
		_putchar('\n');
	for (h = 1; h <= size; h++)
	{
		for (w = 1; w <= (size - h); w++)
			_putchar(' ');
		for (l = 1; l <= h; l++)
			_putchar('#');
		_putchar('\n');
	}
}
