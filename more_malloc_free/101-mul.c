#include "main.h"
#include <stdlib.h>

int is_digit(char *s)
{
	int i = 0;

	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int _strlen(char *s)
{
	int i = 0;

	while (s[i])
		i++;
	return (i);
}

void print_error(void)
{
	char *str = "Error\n";

	while (*str)
		_putchar(*str++);
}

int main(int argc, char *argv[])
{
	char *s1, *s2;
	int len1, len2, len, i, j, k, *res, carry, digit1, digit2;

	if (argc != 3 || !is_digit(argv[1]) || !is_digit(argv[2]))
	{
		print_error();
		return (98);
	}
	s1 = argv[1], s2 = argv[2];
	len1 = _strlen(s1), len2 = _strlen(s2);
	len = len1 + len2;
	res = calloc(sizeof(int), len);
	if (!res)
	{
		print_error();
		return (98);
	}
	for (i = len1 - 1; i >= 0; i--)
	{
		digit1 = s1[i] - '0';
		carry = 0;
		for (j = len2 - 1; j >= 0; j--)
		{
			digit2 = s2[j] - '0';
			k = (len1 - 1 - i) + (len2 - 1 - j);
			carry += res[k] + (digit1 * digit2);
			res[k] = carry % 10;
			carry /= 10;
		}
		if (carry)
			res[k + 1] += carry;
	}
	i = len - 1;
	while (i > 0 && res[i] == 0)
		i--;
	while (i >= 0)
		_putchar(res[i--] + '0');
	_putchar('\n');
	free(res);
	return (0);
}
