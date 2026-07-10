/*
 * File: 100-print_comb3.c
 * Auth: Lalo Rdz
 */
#include <stdio.h>

/**
 * main - Prints all possible different combinations of two digits.
 *
 * Description: The two digits must be different.
 * Return: Always 0 (Success)
 */
int main(void)
{
	int dec, unit;

	for (dec = 48; dec <= 57; dec++)
	{
		for (unit = dec + 1; unit <= 57; unit++)
		{
			putchar(dec);
			putchar(unit);
			if (dec != 56 || unit != 57)
			{
				putchar(44);
				putchar(' ');
			}
		}
	}
	putchar('\n');
	return (0);
}
