#include <stdio.h>
#define FACTOR 100

/**
 * main - Prints first 98 fibonacci numbers
 * fibonacci numbers.
 *
 * Return: Always 0.
 */
int main(void)
{
	int c;
	long int n1, n2, fn;
	long int n11, n22, fn1, fn2;

	n1 = 1;
	n2 = 2;
	printf("%ld, %ld", n1, n2);
	for (c = 3; c < 92; c++)
	{
		fn = n1 + n2;
		n1 = n2;
		n2 = fn;
		printf(", %ld", fn);
	}
	n1 = n1 / FACTOR;
	n2 = n2 / FACTOR;
	n11 = n1 % FACTOR;
	n22 = n2 % FACTOR;
	for (; c <=98; c++)
	{
		fn1 = (n11 + n22) / FACTOR;
		fn2 = (n11 + n22) % FACTOR;
		fn = n1 + n2 + fn1;
		printf(", %ld", fn);
		printf("%02ld", fn2);
		n1 = n2;
		n11 = n22;
		n2 = fn;
		n22 = fn2;
	}
	printf("\n");
	return (0);
}
