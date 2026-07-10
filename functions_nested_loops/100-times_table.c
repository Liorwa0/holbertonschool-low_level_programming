/*
 * File: 100-times_table.c
 * Auth: Lalo Rdz
 */
#include "main.h"

/**
 * print_times_table - Prints the n times table.
 * @n: First printed number
 *
 * Description: Prints the n times table, starting with 0.
 * Return: void
 */
void print_times_table(int n)
{
	int i, j, aux;

	if (n >= 0 && n < 15)
	{
		for (i = 0; i <= n; i++)
		{
			_putchar(48);
			for (j = 1; j <= n; j++)
			{
				_putchar(',');
				_putchar(' ');
				aux = i * j;
				if (aux >= 100)
				{
					_putchar((aux / 100)  + 48);
					aux = aux % 100;
					_putchar((aux / 10)  + 48);
					_putchar((aux % 10)  + 48);
				}
				else
				{
					_putchar(' ');
					if (aux >= 10)
					{
						_putchar((aux / 10) + 48);
						_putchar((aux % 10) + 48);
					}
					else
					{
						_putchar(' ');
						_putchar(aux + 48);
					}
				}
			}
			_putchar('\n');
		}
	}
}
