/*
 * File: 101-print_comb4.c
 * Auth: Lalo Rdz
 */
#include <stdio.h>

/**
 * main - Prints all possible different combinations of three digits.
 *
 * Description: Combinations without repetitions.
 * Return: Always 0 (Success).
 */
int main(void)
{
	int cent, dec, unit;

	for (cent = 48; cent <= 57; cent++)
	{
		for (dec = cent + 1; dec <= 57; dec++)
		{
			for (unit = dec + 1; unit <= 57; unit++)
			{
				putchar(cent);
				putchar(dec);
				putchar(unit);
				if (cent != 55 || dec != 56 || unit != 57)
				{
					putchar(44);
					putchar(' ');
				}
			}
		}
	}
	putchar('\n');
	return (0);
}
