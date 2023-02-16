#include <stdio.h>
#include <string.h>
#include <unistd.h>

/**
 * main - Entry por
 * Return: 1
 */
int main(void)
{
	char str[]  = "and that piece of art is useful\" - Dora Korpar, 2015-10-19\n";

	write(2, "and that piece of art is useful\" - Dora Korpar, 2015-10-19\n", 
	       strlen(str));
	return (1);
}
