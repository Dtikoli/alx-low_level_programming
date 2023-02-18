#include <stdio.h>
/**
 * main - main block
 * Description: Print all possible different combinations of 3 digits.
 * Numbers must be separated by commas and a space.
 * The 3 digits must be different.
 * 012, 120, 102, 021, 201, 210 are considered the same combination.
 * print only the smallest combination of 3 digits.
 * Numbers should be printed in ascending order.
 * Return: 0
 */
int main(void)
{
	int h, t, o;

	for (h = '0'; h < '9'; h++)
	{
		t = h + 1;
		while (t <= '9')
		{
			o = t + 1;
			for ( ;o <= '9'; o++)
			{
				putchar(h);
				putchar(t);
                        	putchar(o);
				if (h < '7')
				{
				putchar(44);
				putchar(32);
				}
			}
			t++;
		}
	}

	putchar('\n');
	return (0);
}
