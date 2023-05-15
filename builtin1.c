#include "shell.h"

/**
<<<<<<< HEAD
 * _myhistory - displays the history list, one command by line, preceded
 *              with line numbers, starting at 0.
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
=======
 * _myhistory - shows history list, single command by line, before 
 *              the line numbers, starting from 0.
 * @info: the structure that contains the potential arguments that maintain
 *        constant function of prototype.
>>>>>>> 30023503089f7e553102eabce247e8e3497a5363
 *  Return: Always 0
 */
int _myhistory(info_t *info)
{
	print_list(info->history);
	return (0);
}

/**
<<<<<<< HEAD
 * unset_alias - sets alias to string
 * @info: parameter struct
 * @str: the string alias
 *
 * Return: Always 0 on success, 1 on error
 */
int unset_alias(info_t *info, char *str)
{
	char *p, c;
	int ret;

	p = _strchr(str, '=');
	if (!p)
		return (1);
	c = *p;
	*p = 0;
	ret = delete_node_at_index(&(info->alias),
		get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
	*p = c;
=======
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
>>>>>>> 30023503089f7e553102eabce247e8e3497a5363
	return (ret);
}

/**
<<<<<<< HEAD
 * set_alias - sets alias to string
 * @info: parameter struct
 * @str: the string alias
 *
 * Return: Always 0 on success, 1 on error
 */
int set_alias(info_t *info, char *str)
{
	char *p;

	p = _strchr(str, '=');
	if (!p)
		return (1);
	if (!*++p)
=======
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
>>>>>>> 30023503089f7e553102eabce247e8e3497a5363
		return (unset_alias(info, str));

	unset_alias(info, str);
	return (add_node_end(&(info->alias), str, 0) == NULL);
}

/**
<<<<<<< HEAD
 * print_alias - prints an alias string
 * @node: the alias node
 *
 * Return: Always 0 on success, 1 on error
 */
int print_alias(list_t *node)
{
	char *p = NULL, *a = NULL;

	if (node)
	{
		p = _strchr(node->str, '=');
		for (a = node->str; a <= p; a++)
		_putchar(*a);
		_putchar('\'');
		_puts(p + 1);
=======
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
>>>>>>> 30023503089f7e553102eabce247e8e3497a5363
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
<<<<<<< HEAD
 * _myalias - mimics the alias builtin (man alias)
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
=======
 * _myalias - imitates alias builtin (man alias)
 * @info: the structure that contains the potential arguments that maintain
 *          constant function of the prototype.
>>>>>>> 30023503089f7e553102eabce247e8e3497a5363
 *  Return: Always 0
 */
int _myalias(info_t *info)
{
	int i = 0;
<<<<<<< HEAD
	char *p = NULL;
=======
	char *q = NULL;
>>>>>>> 30023503089f7e553102eabce247e8e3497a5363
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
<<<<<<< HEAD
		p = _strchr(info->argv[i], '=');
		if (p)
=======
		q = _strchr(info->argv[i], '=');
		if (q)
>>>>>>> 30023503089f7e553102eabce247e8e3497a5363
			set_alias(info, info->argv[i]);
		else
			print_alias(node_starts_with(info->alias, info->argv[i], '='));
	}

	return (0);
}

