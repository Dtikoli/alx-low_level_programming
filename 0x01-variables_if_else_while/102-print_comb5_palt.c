#include <stdio.h>

/**
 * main - Prints numbers between 00 to 99.
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int i, e, g, h, op1, op2;

	h = '0';
	while (h <= '9')
		{
			g = '0';
			while (g <= '9')
			{
				e = '0';
				while (e <= '9')
				{
					i = '0';
					while (i <= '9')
					{
						op1 = (h * 10) + g;
						op2 = (e * 10) + i;
						if (op1 < op2)
						{
							putchar(h);
							putchar(g);
							putchar(' ');
							putchar(e);
							putchar(i);
					
							if (!(h == '9' && g == '8' && e == '9' && i == '9'))							
							putchar(',');
							putchar(' ');
				 		}
						i++;
					}
					e++;
				}
				g++;
			}
			h++;
		}
	putchar('\n');
	return (0);
}
