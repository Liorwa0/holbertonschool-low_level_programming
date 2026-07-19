#include "main.h"
#include <stdlib.h>

/**
 * count_words - helper to count words in a string
 * @str: string to evaluate
 * Return: number of words
 */
int count_words(char *str)
{
	int i, count = 0;

	for (i = 0; str[i]; i++)
	{
		if (str[i] != ' ' && (str[i + 1] == ' ' || str[i + 1] == '\0'))
			count++;
	}
	return (count);
}

/**
 * strtow - splits a string into words
 * @str: string to split
 * Return: pointer to array of strings, or NULL
 */
char **strtow(char *str)
{
	char **tab;
	int i, j, k, len, words;

	if (str == NULL || *str == '\0')
		return (NULL);
	words = count_words(str);
	if (words == 0)
		return (NULL);
	tab = malloc(sizeof(char *) * (words + 1));
	if (tab == NULL)
		return (NULL);
	for (i = 0, k = 0; k < words; k++)
	{
		while (str[i] == ' ')
			i++;
		len = 0;
		while (str[i + len] != ' ' && str[i + len])
			len++;
		tab[k] = malloc(sizeof(char) * (len + 1));
		if (tab[k] == NULL)
		{
			for (j = 0; j < k; j++)
				free(tab[j]);
			free(tab);
			return (NULL);
		}
		for (j = 0; j < len; j++)
			tab[k][j] = str[i++];
		tab[k][j] = '\0';
	}
	tab[k] = NULL;
	return (tab);
}
