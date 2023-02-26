#include <stdio.h>
#define FACTOR 1000000000

/**
 * main - Prints the first 98 Fibonacci numbers
 *
 * Return: Always 0.
 */
int main(void)
{
	int c, b1, b2; /*b1 and b2 are True or False booleans*/
	long int n1, n2, fn, fn1, fn2, n11, n22;

	n1 = 1,	n2 = 2;
	b1 = b2 = 1;
	printf("%ld, %ld", n1, n2);
	for (c = 0; c < 96; c++)
	{
		if (b1)
		{
			fn = n1 + n2;
			printf(", %ld", fn);
			n1 = n2;
			n2 = fn;
		}
		else
		{
			if (b2)
			{
				n11 = n1 % FACTOR;
				n22 = n2 % FACTOR;
				n1 = n1 / FACTOR;
				n2 = n2 / FACTOR;
				b2 = 0;
			}
			fn1 = (n11 + n22) / FACTOR;
			fn2 = (n11 + n22) % FACTOR;
			fn = n1 + n2 + fn1;
			printf(", %ld", fn);
			printf("%ld", fn2);
			n1 = n2;
			n11 = n22;
			n2 = fn;
			n22 = fn2;
		}
		if (((n1 + n2) < 0) && b1 == 1)
			b1 = 0;
	}
	printf("\n");
	return (0);
}
