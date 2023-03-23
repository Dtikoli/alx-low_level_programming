#ifndef _VARIADIC_FUNCTIONS_
#define _VARIADIC_FUNCTIONS_

#include <stdarg.h>
#include <stdio.h>

/**
 * struct datatype - struct
 * @type: signifying data type
 * @f: function pointer
 */
typedef struct datatype
{
	char *type;
	void (*f)(va_list);
} _dt;

int sum_them_all(const unsigned int n, ...);
void print_numbers(const char *separator, const unsigned int n, ...);
void print_strings(const char *separator, const unsigned int n, ...);
void print_all(const char * const format, ...);

#endif /*  #ifndef _VARIADIC_FUNCTIONS_ */
