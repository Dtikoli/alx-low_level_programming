#include <unistd.h>
#include <string.h>

int rand()
{
	static int i = -1;

	i++;
	if (i == 0)
		return 8;
	if (i == 1)
		return 8;
	if (i == 2)
		return 7;
	if (i == 3)
		return 9;
	if (i == 4)
		return 23;
	if (i == 5)
		return 74;
	return i * i % 30000;
}
