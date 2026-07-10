/*
 * File: 102-print_comb5.c
 * Auth: Lalo Rdz
 */

#include <stdio.h>

/**
 * main - Print all the letters except q and e.
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int dec_1, unit_1, dec_2, unit_2;

	for (dec_1 = 48; dec_1 <= 57; dec_1++)
	{
		for (unit_1 = 48; unit_1 <= 57; unit_1++)
		{
			for (dec_2 = dec_1; dec_2 <= 57; dec_2++)
			{
				if (dec_1 == dec_2)
					unit_2 = unit_1 + 1;
				else
					unit_2 = 48;
				for (; unit_2 <= 57; unit_2++)
				{
					putchar(dec_1);
					putchar(unit_1);
					putchar(' ');
					putchar(dec_2);
					putchar(unit_2);
					if (dec_1 != 57 || unit_1 != 56)
					{
						putchar(44);
						putchar(' ');
					}
				}
			}
		}
	}
	putchar('\n');
	return (0);
}
