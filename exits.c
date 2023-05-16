#include "shell.h"

/**
 **_strncpy - copies string
 *@dest: the destination string to copy
 *@src: source string
 *@n: the amount of char to copy
 *Return: the joined string
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i, j;
	char *w = dest;

	i = 0;
	while (src[i] != '\0' && i < n - 1)
	{
		dest[i] = src[i];
		i++;
	}
	if (i < n)
	{
		j = i;
		while (j < n)
		{
			dest[j] = '\0';
			j++;
		}
	}
	return (w);
}

/**
 **_strncat - joins the two strings
 *@dest: first string
 *@src: second string
 *@n: the bytes amount to be used in maximum
 *Return: the joined string
 */
char *_strncat(char *dest, char *src, int n)
{
	int i, j;
	char *w = dest;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0' && j < n)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	if (j < n)
		dest[i] = '\0';
	return (w);
}

/**
 **_strchr - locate char in string
 *@w: string to be parsed
 *@b: the char to look for
 *Return: (w) a pointer to memory area w
 */


char *_strchr(char *w, char b)
{
	do {
		if (*w == b)
			return (w);
	} while (*w++ != '\0');

	return (NULL);
}

