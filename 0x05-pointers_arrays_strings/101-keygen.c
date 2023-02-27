#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	int m;
	int c;
	int t;

	srand(time(NULL));
	for (c = 0, t = 2772; t > 122; c++)
	{
		m = (rand() % 125) + 1;
		printf("%c", myrand);
		t -= m;
	}
	printf("%c", t);

	return (0);
}
