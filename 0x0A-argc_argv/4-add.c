#include <stdio.h>
#include <stdlib.h>

/**
 * main - add positive numbers and print the result
 * @argc: argument count
 * @argv: argument vector, array of strings
 * Description: If no number is passed to program, print 0.
 * If one of the numbers contain non-digits, print Error.
 * Return: 1 if error, 0 if function runs properly.
 */

int main(int argc, char *argv[])
{
	int i, n;
	char *p;
	int sum = 0;

	for (i = 1; argv[i] && i < argc; i++)
	{
		n = strtol(argv[i], &p, 10);
		if (*p)
		{
			printf("Error\n");
			return (1);
		}
		else
			sum += n;
	}
	printf("%d\n", sum);
	return (0);
}
