#include <stdlib.h>
#include "main.h"

/**
 * count_word - helper function 2 count the number of words in a string
 * @s: string to evaluate
 *
 * Return: number of words
 */
int count_word(char *s)
{
	int f, i, words;

	f = 0;
	words = 0;

	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] == ' ')
			f = 0;
		else if (f == 0)
		{
			f = 1;
			words++;
		}
	}

	return (words);
}

/**
 * **strtow - splits a string into words
 * @str: string to split
 *
 * Return: pointer to an array of strings (Success) or NULL (Error)
 */
char **strtow(char *str)
{
	char **matrix, *tmp;
	int i, k = 0, len = 0, words, start, end, f = 0;

	while (*(str + len))
		len++;

	words = count_word(str);
	if (words == 0)
		return (NULL);

	matrix = (char **)malloc(sizeof(char *) * (words + 1));
	if (matrix == NULL)
		return (NULL);

	for (i = 0; i <= len; i++)
	{
		if (str[i] == ' ' || str[i] == '\0')
		{
			if (f)
			{
				end = i;
				tmp = (char *)malloc(sizeof(char) * (f + 1));
				if (tmp == NULL)
					return (NULL);

				while (start < end)
					*tmp++ = str[start++];

				*tmp = '\0';
				matrix[k] = tmp - f;
				k++;
				f = 0;
			}
		}
		else if (f++ == 0)
			start = i;
	}
	matrix[k] = NULL;
	return (matrix);
}
