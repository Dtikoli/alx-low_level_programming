#include "main.h"

/**
 * print_times_table - print multiplication table up to n
 * @n: integer argument
 */
void print_times_table(int n)
{
	int r;
	int c;
	int p;

	if (n >= 0 && n <= 15)
	{
		for (r = 0; r <= n; r++)
		{
			_putchar('0');
			for (c = 1; c <= n; c++)
			{
				p = (r * c);
				if (p <= 9)
				{
					_putchar(',');
					_putchar(' ');
					_putchar(' ');
					_putchar(' ');
					_putchar('0' + p);
				}
				else if (p < 100)
				{
					_putchar(',');
					-putchar(' ');
					_putchar(' ');
					_putchar('0' + (p / 10));
					_putchar('0' + (p % 10));
				}
				else if (p >= 100)
				{
					_putchar(',');
					_putchar(' ');
					_putchar('0' + (p / 100));
					_putchar('0' + ((p / 10) % 10));
					_putchar('0' + (p % 10));
				}
			}
			_putchar('\n');
		}
	}
}
