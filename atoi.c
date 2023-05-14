#include "shell.h"

/**
 * interactive - when shell is interactive the mode returns true
 * @info: the struct address
 *
 * Return:  if interactive mode 1, or else 0
 */
int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delim - characters will be checked if they are delimeters
 * @b: characters to be checked
 * @delim: the string of delimeter
 * Return: 0 false, or else 1 true
 */
int is_delim(char b, char *delim)
{
	while (*delim)
		if (*delim++ == b)
			return (1);
	return (0);
}

/**
 * _isalpha - checking the alphabetic char
 * @b: input into characters
 * Return: if b is alphabetic 1, or else 0
 */

int _isalpha(int b)
{
	if ((b >= 'a' && b <= 'z') || (b >= 'A' && b <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 * _atoi - the string integer will be converted
 * @w: a string will be converted
 * Return: 0 for numbers in string, or else converted number
 */

int _atoi(char *w)
{
	int i, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (i = 0; w[i] != '\0' && flag != 2; i++)
	{
		if (w[i] == '-')
			sign *= -1;

		if (w[i] >= '0' && w[i] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (w[i] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		output = -result;
	else
		output = result;

	return (output);
}
