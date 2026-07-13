#include "main.h"

/**
 * infinite_add - adds two numbers
 * @n1: first number string
 * @n2: second number string
 * @r: buffer to store result
 * @size_r: buffer size
 *
 * Return: pointer to result or 0
 */
char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
	int i = 0, j = 0, k = 0, sum, carry = 0, len1, len2;

	while (n1[i])
		i++;
	while (n2[j])
		j++;
	len1 = i - 1;
	len2 = j - 1;
	if (i + 1 > size_r || j + 1 > size_r)
		return (0);
	r[size_r - 1] = '\0';
	k = size_r - 2;
	while (len1 >= 0 || len2 >= 0 || carry)
	{
		if (k < 0)
			return (0);
		sum = carry + (len1 >= 0 ? n1[len1--] - '0' : 0) +
			(len2 >= 0 ? n2[len2--] - '0' : 0);
		carry = sum / 10;
		r[k--] = (sum % 10) + '0';
	}
	return (&r[k + 1]);
}
