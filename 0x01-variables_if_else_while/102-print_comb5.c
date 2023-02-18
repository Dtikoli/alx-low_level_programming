#include <stdio.h>

/**
 *main - print a num pair from 00-99 but no repeats (00 01, 00 02, 00 03,...)
 *Return: Always 0 (Success)
 */

int main(void)
{
	int ft;
	int fo;
	int st;
	int so;

	for (ft = '0'; ft <= '9'; ft++) /*print first two digit combo*/
	{
		fo = '0';
		while (fo <= '9')
		{
			st = ft;
		 	for ( ; st <= '9'; st++) /*print second of pair*/
			{
				so = fo + 1;
				while (so <= '9')
				{
					putchar(ft);
					putchar(fo);
					putchar(' ');
					putchar(st);
					putchar(so);

					if (!(ft == '9' && fo == '8')) 
					{
						putchar(',');
						putchar(' ');
					}
					so++;
				}
			}
			fo++;
		}
	}
	putchar('\n');

	return (0);
}
