#include "shell.h"

/**
 * **strtow - split string to words. Repeated delimiters are ignored
 * @str: input string
 * @d: delimeter string
 * Return: pointer to array of strings, or NULL with failure
 */

char **strtow(char *str, char *d)
{
	int i, j, k, m, numwords = 0;
	char **w;

	if (str == NULL || str[0] == 0)
		return (NULL);
	if (!d)
		d = " ";
	for (i = 0; str[i] != '\0'; i++)
		if (!is_delim(str[i], d) && (is_delim(str[i + 1], d) || !str[i + 1]))
			numwords++;

	if (numwords == 0)
		return (NULL);
	w = malloc((1 + numwords) * sizeof(char *));
	if (!w)
		return (NULL);
	for (i = 0, j = 0; j < numwords; j++)
	{
		while (is_delim(str[i], d))
			i++;
		k = 0;
		while (!is_delim(str[i + k], d) && str[i + k])
			k++;
		w[j] = malloc((k + 1) * sizeof(char));
		if (!w[j])
		{
			for (k = 0; k < j; k++)
				free(w[k]);
			free(w);
			return (NULL);
		}
		for (m = 0; m < k; m++)
			w[j][m] = str[i++];
		w[j][m] = 0;
	}
	w[j] = NULL;
	return (w);
}

/**
 * **strtow2 - split string to words
 * @str: input string
 * @d: delimeter
 * Return: pointer to array of strings, or NULL with failure
 */
char **strtow2(char *str, char d)
{
	int i, j, k, m, numwords = 0;
	char **w;

	if (str == NULL || str[0] == 0)
		return (NULL);
	for (i = 0; str[i] != '\0'; i++)
		if ((str[i] != d && str[i + 1] == d) ||
				    (str[i] != d && !str[i + 1]) || str[i + 1] == d)
			numwords++;
	if (numwords == 0)
		return (NULL);
	w = malloc((1 + numwords) * sizeof(char *));
	if (!w)
		return (NULL);
	for (i = 0, j = 0; j < numwords; j++)
	{
		while (str[i] == d && str[i] != d)
			i++;
		k = 0;
		while (str[i + k] != d && str[i + k] && str[i + k] != d)
			k++;
		w[j] = malloc((k + 1) * sizeof(char));
		if (!w[j])
		{
			for (k = 0; k < j; k++)
				free(w[k]);
			free(w);
			return (NULL);
		}
		for (m = 0; m < k; m++)
			w[j][m] = str[i++];
		w[j][m] = 0;
	}
	w[j] = NULL;
	return (w);
}

