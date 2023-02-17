#include <stdio.h>

/**
 * main - Entry point
 * Description: Prints numbers from 0 to 9
 * Return: Always 0 (Succes).
 */
int main(void)
{
	int ch;

	for (ch = '0'; ch <= '9'; ch++)
	{
		putchar(ch);
	}
	putchar('\n');
	return (0);
}
