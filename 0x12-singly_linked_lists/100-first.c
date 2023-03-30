#include <stdio.h>

/**
 * ahead_main - executes this function ahead of main function
 * Note: made possible by prior declaration of "__attribute__ ((constructor))"
 */
void __attribute__ ((constructor)) ahead_main()
{
	printf("You're beat! and yet, you must allow,\n");
	printf("I bore my house upon my back!\n");
}
