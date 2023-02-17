#include <stdio.h>
/**
 * main - main block
 * Description: Print all possible combinations of two digits.
 * Numbers must be separated by commas and a space.
 * 01 and 10 are considered as the same combination of the two digits.
 * Print only the smallest combination of two digits.
 * Numbers should be printed in ascending order, with two digits.
 * Return: Always 0 (Succes)
 */
int main(void)
{
	int t, d, c;

	t = 0;

	while (t <= 99)
	{
		d = t / 10; /* singles digit */
		c = t % 10; /* doubles digit */

		if (c > d)
		{
			putchar(d + '0');
			putchar(c + '0');

			if (t < 89)
			{
				putchar(44);
				putchar(32);
			}
		}

		t++;
	}
	putchar('\n');

	return (0);
}
