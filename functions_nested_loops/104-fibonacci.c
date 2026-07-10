#include <stdio.h>

/**
 * main - finds and prints the first 98 Fibonacci numbers,
 * starting with 1 and 2, followed by a new line.
 *
 * Return: Always 0.
 */
int main(void)
{
	unsigned long int i, f1 = 1, f2 = 2, next;
	unsigned long int f1_h, f1_t, f2_h, f2_t, next_h, next_t;

	printf("%lu, %lu", f1, f2);

	for (i = 3; i <= 91; i++)
	{
		next = f1 + f2;
		printf(", %lu", next);
		f1 = f2;
		f2 = next;
	}

	f1_h = f1 / 1000000000;
	f1_t = f1 % 1000000000;
	f2_h = f2 / 1000000000;
	f2_t = f2 % 1000000000;

	for (i = 92; i <= 98; i++)
	{
		next_h = f1_h + f2_h;
		next_t = f1_t + f2_t;
		
		if (next_t >= 1000000000)
		{
			next_h += 1;
			next_t %= 1000000000;
		}
		
		printf(", %lu%09lu", next_h, next_t);
		f1_h = f2_h;
		f1_t = f2_t;
		f2_h = next_h;
		f2_t = next_t;
	}
	printf("\n");

	return (0);
}
