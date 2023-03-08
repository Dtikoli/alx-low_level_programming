#include "main.h"

/**
 * sqrt_help - helper function to solve _sqrt_recursion
 * @n: number whose square root is to be determined
 * @r: incrementer to square root
 * Return: square root if natural square root, or -1 if none found
 */

int sqrt_help(int n, int r)
{
	int s;

	s = r * r;
	if (s == n)
		return (r);
	else if (s < n)
		return (sqrt_help(n, r + 1));
	else
		return (-1);
}

/**
 * _sqrt_recursion - return the natural square root of a number
 * @n: int number
 * Return: If no natural square root, return -1. Else return natural
 * square root
 */

int _sqrt_recursion(int n)
{
	return (sqrt_help(n, 0));
}
