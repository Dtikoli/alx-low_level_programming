#include <stdlib.h>
#include <time.h>
#include <stdio.h>

/**
 * main - Entry point
 * Description: Prints a random number and determine
 * how it compares with some given numbers.
 * Return: Always 0 (Succes).
 */
int main(void)
{
	int n;
	int r;

	srand(time(0));
	n = rand() - RAND_MAX / 2;
	r = n % 10;
	if (r > 5)
		printf("Last digit of %i is %i and greater than 5\n", n, r);
	else if (r == 0)
		printf("Last digit of %i is %i and is 0\n", n, r);
	else if (r < 6 && r != 0)
		printf("Last digit of %i is %i and less than 6 and not 0\n", n, r);
	return (0);
}
