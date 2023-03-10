#include <stdio.h>
#include <stdlib.h>

/**
 * main - prints the minimal number of coins for a change
 * @argc: number of arguments
 * @argv: array of arguments
 * Return: 0
 */
int main(int argc, char *argv[])
{
	int i, cents;
	int num = 0;
	int coins[] = {25, 10, 5, 2, 1};

	if (argc != 2)
	{
		printf("Error\n");
		return (1);
	}
	cents = atoi(argv[1]);
	for (i = 0; coins[i] && cents > 0; i++)
	{
		num += cents / coins[i];
		cents = cents % coins[i];
	}
	printf("%d\n", num);
	return (0);
}
