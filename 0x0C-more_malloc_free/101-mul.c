#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

/**
 * isNumber - checks if a string is a number
 * @s: string to check
 * Return: 1 if number, 0 if not
 */
int isNumber(char *s)
{
	int i;

	for (i = 0; s[i]; i++)
		if (s[i] < '0' || s[i] > '9')
			return (0);
	return (1);
}

/**
 * mul_print - prints the result of the multiplication
 * @mul: array of integers
 * @len: length of result
 * Return: void
 */
void mul_print(int *mul, int len)
{
	int i;

	/* remove leading zeros */
	for (i = 0; i < len && mul[i] == 0; i++)
		;

	/* if all digits are 0, print 0 */
	if (i == len)
		printf("0");

	/* print the result */
	for (; i < len; i++)
		printf("%d", mul[i]);

	printf("\n");
}

/**
 * main - multiplies two positive numbers
 * @ac: number of arguments
 * @av: array of arguments
 * Return: 0
 */
int main(int ac, char **av)
{
	int i, j, nl1, nl2, mul, add;
	int *ptr;

	if (ac != 3 || !isNumber(av[1]) || !isNumber(av[2]))
	{
		printf("Error\n");
		exit(98);
	}

	nl1 = strlen(av[1]);
	nl2 = strlen(av[2]);

	ptr = calloc(nl1 + nl2, sizeof(int));
	if (ptr == NULL)
	{
		printf("Error\n");
		exit(98);
	}

	/* multiply each digit of num1 with num2 */
	for (i = nl1 - 1; i >= 0; i--)
	{
		for (j = nl2 - 1; j >= 0; j--)
		{
			/* multiply each digit and add to result */
			mul = (av[1][i] - '0') * (av[2][j] - '0');

			/* add to previous result */
			add = ptr[i + j + 1] + mul;

			/* update result */
			ptr[i + j] += add / 10;
			ptr[i + j + 1] = add % 10;
		}
	}

	/* print result and free the allocated memory */
	mul_print(ptr, nl1 + nl2);
	free(ptr);
	return (0);
}

