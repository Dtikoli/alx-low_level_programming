#include <stdio.h>

/**
 * main - Entry point
 * Description: Prints alphabets a to z in lower case
 * Return: Always 0 (Succes).
 */
int main(void)
{
	char ch;

	for (ch = 'a'; ch <= 'z'; ch++)
	{
		putchar(ch);
	}
	for (ch = 'A'; ch <= 'Z'; ch++)
	{
		putchar(ch);
	}
	putchar('\n');
	return (0);
}
