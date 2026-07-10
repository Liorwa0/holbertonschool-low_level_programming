#include "main.h"
/**
 * print_triangle - prints reverse triangle
 * @size: size
 * Return: nothing
 */

void print_triangle(int size)
{
int i;
int j;
if (size <= 0)
{
_putchar('\n');
return;
}
for (i = 1; i <= size; i++)
{
for (j = i; j < size; j++)
_putchar(' ');
for (j = 0; j < i; j++)
_putchar(35);
_putchar('\n');
}
}
