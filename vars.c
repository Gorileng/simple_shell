#include "shell.h"

/**
 * is_chain - test whether the current character in the buffer is the chain delimeter
 * @info: parameter struct
 * @buf: character buffer
 * @q: the address of the current position in the buffer
 *
 * Return: 1 when is chain delimeter, 0 otherwise
 */
int is_chain(info_t *info, char *buf, size_t *q)
{
	size_t j = *q;

	if (buf[j] == '|' && buf[j + 1] == '|')
	{
		buf[j] = 0;
		j++;
		info->cmd_buf_type = CMD_OR;
	}
	else if (buf[j] == '&' && buf[j + 1] == '&')
	{
		buf[j] = 0;
		j++;
		info->cmd_buf_type = CMD_AND;
	}
	else if (buf[j] == ';') /* found end of this command */
	{
		buf[j] = 0; /* replace semicolon with null */
		info->cmd_buf_type = CMD_CHAIN;
	}
	else
		return (0);
	*q = j;
	return (1);
}

/**
 * check_chain - check if we should continue chaining based on the last status
 * @info: parameter struct
 * @buf: character buffer
 * @q: address of the current position in the buf
 * @i: starting position in the buf
 * @len: length of the buf
 *
 * Return: Void
 */

void check_chain(info_t *info, char *buf, size_t *q, size_t i, size_t len)
{
	size_t j = *q;

	if (info->cmd_buf_type == CMD_AND)
	{
		if (info->status)
		{
			buf[i] = 0;
			j = len;
		}
	}
	if (info->cmd_buf_type == CMD_OR)
	{
		if (!info->status)
		{
			buf[i] = 0;
			j = len;
		}
	}

	*q = j;
}

/**
 * replace_alias - replace alias in tokenized string
 * @info: parameter struct
 *
 * Return: 1 when is replaced, 0 otherwise
 */
int replace_alias(info_t *info)
{
	int i;
	list_t *node;
	char *q;

	for (i = 0; i < 10; i++)
	{
		node = node_starts_with(info->alias, info->argv[0], '=');
		if (!node)
			return (0);
		free(info->argv[0]);
		q = _strchr(node->str, '=');
		if (!q)
			return (0);
		q = _strdup(q + 1);
		if (!q)
			return (0);
		info->argv[0] = q;
	}
	return (1);
}

/**
 * replace_vars - replace vars in tokenized string
 * @info: parameter struct
 *
 * Return: 1 when replaced, 0 otherwise
 */
int replace_vars(info_t *info)
{
	int i = 0;
	list_t *node;

	for (i = 0; info->argv[i]; i++)
	{
		if (info->argv[i][0] != '$' || !info->argv[i][1])
			continue;

		if (!_strcmp(info->argv[i], "$?"))
		{
			replace_string(&(info->argv[i]),
					_strdup(convert_number(info->status, 10, 0)));
			continue;
		}
		if (!_strcmp(info->argv[i], "$$"))
		{
			replace_string(&(info->argv[i]),
					_strdup(convert_number(getpid(), 10, 0)));
			continue;
		}
		node = node_starts_with(info->env, &info->argv[i][1], '=');
		if (node)
		{
			replace_string(&(info->argv[i]),
					_strdup(_strchr(node->str, '=') + 1));
			continue;
		}
		replace_string(&info->argv[i], _strdup(""));

	}
	return (0);
}

/**
 * replace_string - replace the string
 * @old: the address of the old string
 * @new: the new string
 *
 * Return: 1 when replaced, 0 otherwise
 */
int replace_string(char **old, char *new)
{
	free(*old);
	*old = new;
	return (1);
}

