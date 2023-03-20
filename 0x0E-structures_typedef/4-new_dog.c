#include "dog.h"
#include <stdlib.h>

/**
 * new_dog - create a new dog
 * @name: char string name
 * @age: int age
 * @owner: char string owner
 * Return: pointer to new dog
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	struct dog *_dog;
	int i, j, k;
	char *m, *n;

	_dog = malloc(sizeof(struct dog));
	if (doge == NULL)
		return (NULL);

	for (i = 0; name[i]; i++)
		;
	for (j = 0; owner[j]; j++)
		;

	n = malloc(sizeof(*n) * i + 1);
	if (n == NULL)
	{
		free(_dog);
		return (NULL);
	}
	m = malloc(sizeof(*m) * j + 1);
	if (m == NULL)
	{
		free(n);
		free(_dog);
		return (NULL);
	}
	for (k = 0; k <= i; k++)
		n[k] = name[k];
	for (k = 0; k <= j; k++)
		m[k] = owner[k];

	_dog->name = n;
	_dog->age = age;
	_dog->owner = m;

	return (_dog);
}
