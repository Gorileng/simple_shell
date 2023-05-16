#include "shell.h"

/**
 * _erratoi - convert string to integer
 * @w: the string to convert
 * Return: 0 if there's no numbers in the string, converted number otherwise
 *       -1 error
 */

int _erratoi(char *w)
{
	int i = 0;
	unsigned long int result = 0;

	if (*w == '+')
		w++;  /* TODO: why does this make main return 255? */
	for (i = 0;  w[i] != '\0'; i++)
	{
		if (w[i] >= '0' && w[i] <= '9')
		{
			result *= 10;
			result += (w[i] - '0');
			if (result > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (result);
}

/**
 * print_error - print error message
 * @info: the parameter and return info struct
 * @estr: string contain stated error type
 * Return: 0 if there's no numbers in the string, converted number otherwise
 *        -1 error
 */

void print_error(info_t *info, char *estr)
{
	_eputs(info->fname);
	_eputs(": ");
	print_d(info->line_count, STDERR_FILENO);
	_eputs(": ");
	_eputs(info->argv[0]);
	_eputs(": ");
	_eputs(estr);
}

/**
 * print_d - the function prints decimal (integer) number (base 10)
 * @input: input
 * @fd: filedescriptor write to
 *
 * Return: number of the characters print
 */

int print_d(int input, int fd)
{
	int (*__putchar)(char) = _putchar;
	int i, count = 0;
	unsigned int _abs_, current;

	if (fd == STDERR_FILENO)
		__putchar = _eputchar;
	if (input < 0)
	{
		_abs_ = -input;
		__putchar('-');
		count++;
	}
	else
		_abs_ = input;
	current = _abs_;
	for (i = 1000000000; i > 1; i /= 10)
	{
		if (_abs_ / i)
		{
			__putchar('0' + current / i);
			count++;
		}
		current %= i;
	}
	__putchar('0' + current);
	count++;

	return (count);
}

/**
 * convert_number - the converter function, clone of itoa
 * @num: the number
 * @base: the base
 * @flags: the argument flags
 *
 * Return: the string
 */
char *convert_number(long int num, int base, int flags)
{
	static char *array;
	static char buffer[50];
	char sign = 0;
	char *ptr;
	unsigned long n = num;

	if (!(flags & CONVERT_UNSIGNED) && num < 0)
	{
		n = -num;
		sign = '-';

	}
	array = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';

	do	{
		*--ptr = array[n % base];
		n /= base;
	} while (n != 0);

	if (sign)
		*--ptr = sign;
	return (ptr);
}

/**
 * remove_comments - the function will replace first instance of '#' with '\0'
 * @buf: address string to modify
 *
 * Return: Always 0;
 */
void remove_comments(char *buf)
{
	int i;

	for (i = 0; buf[i] != '\0'; i++)
		if (buf[i] == '#' && (!i || buf[i - 1] == ' '))
		{
			buf[i] = '\0';
			break;
		}
}

