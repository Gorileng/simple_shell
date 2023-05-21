#include "shell.h"

/**
 * _strlen - returns length of the string
 * @w: string whom length to check
 *
 * Return: integers length of the string
 */
int _strlen(char *w)
{
	int i = 0;

	if (!w)
		return (0);

	while (*w++)
		i++;
	return (i);
}

/**
 * _strcmp - perform the lexicographic that compares two strangs.
 * @s1: first strang
 * @s2: second strang
 *
 * Return: negative when s1 < s2, positive when s1 > s2, zero when s1 == s2
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	if (*s1 == *s2)
		return (0);
	else
		return (*s1 < *s2 ? -1 : 1);
}

/**
 * starts_with - checks whether the needle start with the haystack
 * @haystack: string search
 * @needle: substring to find
 *
 * Return: the address of the next character of the haystack or NULL
 */
char *starts_with(const char *haystack, const char *needle)
{
	while (*needle)
		if (*needle++ != *haystack++)
			return (NULL);
	return ((char *)haystack);
}

/**
 * _strcat - joins the two strings
 * @dest: destination buffer
 * @src: source buffer
 *
 * Return: the pointer to the destination buffer
 */
char *_strcat(char *dest, char *src)
{
	char *ret = dest;

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = *src;
	return (ret);
}

