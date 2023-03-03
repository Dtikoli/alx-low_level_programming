#include "main.h"
#include <stdio.h>

/**
 * print_diagsums - print sums of diagonals in matrix
 * @a: matrix
 * @size: size of matrix
 */
void print_diagsums(int *a, int size)
{

        int diag_sum1 = 0;
        int diag_sum2 = 0;
        int row, i;

        for (row = 0; row < size; row++)
        {
                i = (row * size) + row;
                diag_sum1 += a[i];
        }
        for (row = 1; row <= size; row++)
        {
                i = (row * size) - row;
                diag_sum2 += a[i];
        }
        printf("%d, %d\n", diag_sum1, diag_sum2);
}
