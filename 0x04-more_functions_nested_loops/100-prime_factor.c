#include <stdio.h>

/**
 * main - prints largest prime factor.
 * Return: Always 0.
 */
int main(void)
{
	long int n;
	long int pf; /* Prime factors */

	n = 612852475143;
	for (pf = 2; pf < n; pf++)
	{
		if (n % pf == 0)
		{
			n /= pf;
		}
	}
	printf("%ld\n", pf);
	return (0);
}
