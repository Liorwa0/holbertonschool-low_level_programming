#include "main.h"

/**
 * _isdigit - checks for a digit
 * @c: int
 * Return: 1 if c digit 0 otherwise
 */

int _isdigit(int c)
{
if (c >= 48 && c <= 57)
{
return (1);
}
return (0);
}
