#include <stdio.h>
#define MAX 1000000000

/**
 * main - Prints first 98 fibonacci numbers
 * fibonacci numbers.
 *
 * Return: Always 0.
 */
int main(void)
{
	int c;
	unsigned long int n1, n2, fn;
	unsigned long int n11, n22, fn1, fn2;

	n1 = 1;
	n2 = 2;
	printf("%lu, %lu", n1, n2);
	for (c = 3; c < 90; c++)
	{
		fn = n1 + n2;
		n1 = n2;
		n2 = fn;
		printf(", %lu", fn);
	}
	n1 = n1 / MAX;
	n2 = n2 / MAX;
	n11 = n1 % MAX;
	n22 = n2 % MAX;
	for (; c <= 98; c++)		
	{	
		fn1 = (n11 + n22) / MAX;
		fn2 = (n11 + n22) % MAX;
		fn = n1 + n2 + fn1;
		printf(", %lu", fn);
		printf("%lu", fn2);
		n1 = n2;
		n11 = n22;
		n2 = fn;
		n22 = fn2;
	}
	printf("\n");
	return (0);
}
