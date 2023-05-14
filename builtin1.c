#include "shell.h"

/**
 * _myhistory - shows history list, single command by line, before 
 *              the line numbers, starting from 0.
 * @info: the structure that contains the potential arguments that maintain
 *        constant function of prototype.
 *  Return: Always 0
 */
int _myhistory(info_t *info)
{
	print_list(info->history);
	return (0);
}

/**
 * unset_alias - sets the string to alias 
 * @info: the parameter struct
 * @str: string alias
 *
 * Return: Always 0 success, 1 error
 */
int unset_alias(info_t *info, char *str)
{
	char *q, b;
	int ret;

	q = _strchr(str, '=');
	if (!q)
		return (1);
	b = *q;
	*q = 0;
	ret = delete_node_at_index(&(info->alias),
		get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
	*q = b;
	return (ret);
}

/**
 * set_alias - sets string to alias 
 * @info: the parameter struct
 * @str: string alias
 *
 * Return: Always 0 success, 1 error
 */
int set_alias(info_t *info, char *str)
{
	char *q;

	q = _strchr(str, '=');
	if (!q)
		return (1);
	if (!*++q)
		return (unset_alias(info, str));

	unset_alias(info, str);
	return (add_node_end(&(info->alias), str, 0) == NULL);
}

/**
 * print_alias - prints the alias of string
 * @node: alias node
 *
 * Return: Always 0 success, 1 error
 */
int print_alias(list_t *node)
{
	char *q = NULL, *a = NULL;

	if (node)
	{
		q = _strchr(node->str, '=');
		for (a = node->str; a <= q; a++)
		_putchar(*a);
		_putchar('\'');
		_puts(q + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * _myalias - imitates alias builtin (man alias)
 * @info: the structure that contains the potential arguments that maintain
 *          constant function of the prototype.
 *  Return: Always 0
 */
int _myalias(info_t *info)
{
	int i = 0;
	char *q = NULL;
	list_t *node = NULL;

	if (info->argc == 1)
	{
		node = info->alias;
		while (node)
		{
			print_alias(node);
			node = node->next;
		}
		return (0);
	}
	for (i = 1; info->argv[i]; i++)
	{
		q = _strchr(info->argv[i], '=');
		if (q)
			set_alias(info, info->argv[i]);
		else
			print_alias(node_starts_with(info->alias, info->argv[i], '='));
	}

	return (0);
}

