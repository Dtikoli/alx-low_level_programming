#include <stdlib.h>
#include "main.h"

/**
  * malloc_checked - allocates memory using malloc
  * Description: if malloc fails, terminate process with status value 98
  * @b: the number of bytes to be allocated
  * Return: a void pointer to the allocated memory
  */
void *malloc_checked(unsigned int b)
{
	void *p;

	p = malloc(b);
	if (p == NULL)
		exit(98);
	return (p);
}
