#include "main.h"

/**
 * print_chessboard - print chessboard given set 2D array
 * @a: 2D array
 */
void print_chessboard(char (*a)[8])
{
	int i;
	int j;

	for (i = 0; 1 < 8; i++)
	{
		for (j = 0; j < 8; j++)
			_putchar(a[i][j]);
		_putchar('\n');
	}
}
