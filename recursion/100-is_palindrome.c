#include "main.h"

/**
 * _strlen_recursion - returns the length of a string
 * @s: string to measure
 * Return: length
 */
int _strlen_recursion(char *s)
{
	if (*s == '\0')
		return (0);
	return (1 + _strlen_recursion(s + 1));
}

/**
 * check_palindrome - compares characters from start and end
 * @s: string
 * @len: current length index
 * @i: current iteration index
 * Return: 1 if palindrome, 0 otherwise
 */
int check_palindrome(char *s, int len, int i)
{
	if (i >= len)
		return (1);
	if (s[i] != s[len])
		return (0);
	return (check_palindrome(s, len - 1, i + 1));
}

/**
 * is_palindrome - checks if a string is a palindrome
 * @s: string to check
 * Return: 1 if palindrome, 0 otherwise
 */
int is_palindrome(char *s)
{
	int len = _strlen_recursion(s);

	if (len <= 1)
		return (1);
	return (check_palindrome(s, len - 1, 0));
}
