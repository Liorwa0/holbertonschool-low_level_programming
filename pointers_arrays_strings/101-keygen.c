#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * main - generates a random valid password for 101-crackme
 *
 * Return: 0 always
 */
int main(void)
{
	int sum = 0, n = 0;
	char pwd[100];
	time_t t;

	srand((unsigned int)time(&t));
	while (sum < 2772 - 127)
	{
		pwd[n] = (rand() % 94) + 33;
		sum += pwd[n];
		n++;
	}
	pwd[n] = 2772 - sum;
	pwd[n + 1] = '\0';
	printf("%s", pwd);
	return (0);
}
