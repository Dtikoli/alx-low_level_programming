#include <stdio.h>

/**
 * main - Prints the sum of all natural numbers below 1024
 * that are multiplies of 3 or 5
 *
 * Return: Always 0.
 */
int main(void)
{
	int n, s = 0;

	for (n = 1; n < 1024; n++)
	{
		if ((n % 3) == 0 || (n % 5) == 0)
			s += n;
	}
	printf("%d\n", s);
	return (0);
}
