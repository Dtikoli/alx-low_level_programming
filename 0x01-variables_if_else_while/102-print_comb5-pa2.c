#include <stdio.h>

/**
 *main - print a num pair from 00-99 but no repeats (00 01, 00 02, 00 03,...)
 *Return: Always 0 (Success)
 */

int main(void)
{
	int tf;
	int of;
	int ts;
	int os;

	for (tf = '0'; tf <= '9'; tf++) /*print first two digit combo*/
	{
		for (of = '0'; of <= '9'; of++)
		{
		 	for (ts = '0'; ts <= '9'; ts++) /*print second of pair*/
			{
				for (os = '0'; os <= '9'; os++)
				{
					if (tf < ts || (tf == ts && of < os))
					{	putchar(tf);
						putchar(of);
						putchar(' ');
						putchar(ts);
						putchar(os);
	
						if (!((tf == '9' && of == '8') && 
					 	   (ts == '9' && os == '9')))
						{
							putchar(',');
							putchar(' ');
						}
					}
				}
			}
		}
	}
	putchar('\n');

	return (0);
}
