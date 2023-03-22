#include "function_pointers.h"

/**
 * print_name - Print a name from a function pointer
 * @name: char pointer to the name to print
 * @f: function pointer that takes a string argument
 * Return: nothing
 */
void print_name(char *name, void (*f)(char *))
{
	f(name);
}
