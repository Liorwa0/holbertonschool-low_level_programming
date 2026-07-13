#include "main.h"

/**
 * cap_string - capitalizes all words of a string
 * @s: pointer to the string
 *
 * Return: pointer to the modified string
 */
char *cap_string(char *s)
{
	int i = 0, j;
	char sep[] = " \t\n,;.!?\"(){}";

	if (s[i] >= 'a' && s[i] <= 'z')
		s[i] -= 32;

	while (s[i] != '\0')
	{
		for (j = 0; sep[j] != '\0'; j++)
		{
			if (s[i] == sep[j])
			{
				if (s[i + 1] >= 'a' && s[i + 1] <= 'z')
					s[i + 1] -= 32;
			}
		}
		i++;
	}
	return (s);
}
