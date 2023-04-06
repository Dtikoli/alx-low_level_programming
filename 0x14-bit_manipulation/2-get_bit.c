#include "main.h"

/**
 * get_bit - returns the value of a bit at an index
 * @n: number to get bit from
 * @index: index within binary number
 * Return: bit 0 or 1, (-1 if fails)
 */
int get_bit(unsigned long int n, unsigned int index)
{
	unsigned long int tmp;
	unsigned int bit_max;

	/* validate the range of the given index */
	bit_max = sizeof(unsigned long int) * 8;
	if (index > bit_max)
		return (-1);

	/* shift given index to the right to determine tmp */
	tmp = n >> index;

	return (tmp & 1);
}
