#include "main.h"

/**
 * prime_help - helper function for is_prime_number
 * @n: number
 * @j: incrementer
 *
 * Return: 1 if n is a prime number, otherwise 0
 */
int prime_help(int n, int j)
{
	if (n % j == 0)
	{
		if (j == n)
			return (1);
		else
			return (0);
	}
	return (prime_help(n, j + 1));
}

/**
 * is_prime_number - returns 1 if the input integer is a prime number,
 * otherwise return 0
 * @n: number
 *
 * Return: 1 if n is a prime number, otherwise 0
 */

int is_prime_number(int n)
{
	if (n <= 1)
		return (0);
	return (prime_help(n, 2));
}
