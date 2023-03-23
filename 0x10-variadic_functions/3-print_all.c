#include "variadic_functions.h"

/**
 * _printchar - print char type element from va_list
 * @list: va_list passed to function
 */
void _printchar(va_list list)
{
	printf("%c", va_arg(list, int));
}

/**
 * _printstr - print string element from va_list
 * @list: va_list passed to function
 */
void _printstr(va_list list)
{
	char *s;

	s = va_arg(list, char *);
	printf("%s", s == NULL ? "(nil)" : s);
}

/**
 * _printfloat - print float type element from va_list
 * @list: va_list passed to function
 */
void _printfloat(va_list list)
{
	printf("%f", va_arg(list, double));
}

/**
 * _printint - print int type element from va_list
 * @list: va_list passed to function
 */
void _printint(va_list list)
{
	printf("%d", va_arg(list, int));
}

/**
 * print_all - print anything passed if char, int, float, or string.
 * @format: string of formats to use and print
 */
void print_all(const char * const format, ...)
{
	unsigned int i = 0, j;
	va_list args;
	char *delim;

	_dt list[] = {
		{ "c", _printchar },
		{ "f", _printfloat },
		{ "s", _printstr },
		{ "i", _printint },
		{ NULL, NULL }
	};

	delim = "";
	va_start(args, format);
	while (format && format[i])
	{
		j = 0;
		while (j < 4)
		{
			if (format[i] == list[j].type[0])
			{
				printf("%s", delim);
				list[j].f(args);
				delim = ", ";
			}
			j++;
		}
		i++;
	}
	printf("\n");
	va_end(args);
}
