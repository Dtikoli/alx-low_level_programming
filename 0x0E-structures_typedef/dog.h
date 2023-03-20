#ifndef _DOG_H_
#define _DOG_H_

/**
 * struct dog - structure definition of a dog
 * @name: character string representing name of dog
 * @age: float representing age of dog
 * @owner: character string representing owner of dog
 */
typedef struct dog
{
	char *name;
	float age;
	char *owner;
} dog_t;

void init_dog(struct dog *d, char *name, float age, char *owner);
void print_dog(struct dog *d);
dog_t *new_dog(char *name, float age, char *owner);
void free_dog(dog_t *d);
#endif /* #ifndef _DOG_H_ */
