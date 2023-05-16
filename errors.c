#include "shell.h"

/**
 * _eputs - print the input string
 * @str: string to print
 *
 * Return: nothing
 */
void _eputs(char *str)
{
	int i = 0;

	if (!str)
		return;
	while (str[i] != '\0')
	{
		_eputchar(str[i]);
		i++;
	}
}

/**
 * _eputchar - write char b to stderr
 * @b: char to print
 *
 * Return: success 1.
 * On error, -1 returned, errno will be set properly.
 */
int _eputchar(char b)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (b == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(2, buf, i);
		i = 0;
	}
	if (b != BUF_FLUSH)
		buf[i++] = b;
	return (1);
}

/**
 * _putfd - write char b to the given fd
 * @b: prints the character
 * @fd: filedescriptor write to
 *
 * Return: success 1.
 * On error, -1 returned, errno will be set properly.
 */

int _putfd(char b, int fd)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (b == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(fd, buf, i);
		i = 0;
	}
	if (b != BUF_FLUSH)
		buf[i++] = b;
	return (1);
}

/**
 * _putsfd - print input string
 * @str: string to print
 * @fd: filedescriptor write into
 *
 * Return: number of the characters put
 */
int _putsfd(char *str, int fd)
{
	int i = 0;

	if (!str)
		return (0);
	while (*str)
	{
		i += _putfd(*str++, fd);
	}
	return (i);
}

