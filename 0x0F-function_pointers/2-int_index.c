#include "function_pointers.h"

/**
 * int_index - Function that searches for an integer
 * @array: array of integers
 * @size: size of array
 * @cmp: function pointer
 * Return: index of first element that matches with `cmp`, or -1 if none found
 */
int int_index(int *array, int size, int (*cmp)(int))
{
	int t;

	if (array && cmp)
	{
		if (size <= 0)
			return (-1);
		for (t = 0; t < size; t++)
		{
			if (cmp(array[t]))
				return (t);
		}
	}
	return (-1);
}
