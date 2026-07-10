#include "main.h"

/**
 * print_most_numbers - print 0 to 9 except for 2 and 4
 *
 * Return: nothing
 */
void print_most_numbers(void)
{
int i;
for (i = 48; i <= 57; i++)
{
if (i != 52 && i != 50)
{
_putchar(i);
}
}
_putchar('\n');
}
