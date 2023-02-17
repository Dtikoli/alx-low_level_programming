#include <stdio.h>

/**
 * main - Entry point
 * Description: Printse all lower case aphabets except e and q
 * Return: Always 0 (Succes).
 */
int main(void)
{
	char ch = 'a';

	while (ch <= 'z')
	{
		if ((ch != 'e') && (ch != 'q'))
			{
			putchar(ch);
			}
		ch++;
	}
	putchar('\n');
	return (0);
}
