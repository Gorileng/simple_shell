#include "shell.h"

/**
 * _strcpy - copy the string
 * @dest: destination
 * @src: source
 *
 * Return: the pointer to the destination
 */
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	if (dest == src || src == 0)
		return (dest);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

/**
 * _strdup - duplicate string
 * @str: string to duplicate
 *
 * Return: the pointer to duplicated string
 */

char *_strdup(const char *str)
{
	int length = 0;
	char *ret;

	if (str == NULL)
		return (NULL);
	while (*str++)
		length++;
	ret = malloc(sizeof(char) * (length + 1));
	if (!ret)
		return (NULL);
	for (length++; length--;)
		ret[length] = *--str;
	return (ret);
}

/**
 * _puts - print the input of the string
 * @str: string to be printed
 *
 * Return: nothing
 */
void _puts(char *str)
{
	int i = 0;

	if (!str)
		return;
	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
	}
}

/**
 * _putchar - write char b to stdout
 * @b: The char to print
 *
 * Return: success 1.
 * error, -1 is returned, and errno is set properly.
 */


int _putchar(char b)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (b == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(1, buf, i);
		i = 0;
	}
	if (b != BUF_FLUSH)
		buf[i++] = b;
	return (1);
}

