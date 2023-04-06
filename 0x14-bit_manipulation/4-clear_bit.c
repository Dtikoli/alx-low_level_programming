#include "main.h"

/**
 * clear_bit - sets the value of a bit to 0 at an index
 * @n: decimal number
 * @index: index within binary number
 * Return:  1, -1 if error
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int tmp = 1;
	unsigned int bit_max;

	/* validate the range of the given index */
	bit_max = sizeof(unsigned long int) * 8;
	if (index > bit_max)
		return (-1);

	/* create tmp with 0 at the index to work on it */
	tmp = ~(tmp << index);
	*n = (*n & tmp);

	return (1);

}
