#include "shell.h"

/**
 * list_len - determine the length of the linked list
 * @e: the pointer for the first node
 *
 * Return: the size list
 */
size_t list_len(const list_t *e)
{
	size_t i = 0;

	while (e)
	{
		e = e->next;
		i++;
	}
	return (i);
}

/**
 * list_to_strings - return array of string list->str
 * @head: the pointer for the first node
 *
 * Return: array strings
 */
char **list_to_strings(list_t *head)
{
	list_t *node = head;
	size_t i = list_len(head), j;
	char **strs;
	char *str;

	if (!head || !i)
		return (NULL);
	strs = malloc(sizeof(char *) * (i + 1));
	if (!strs)
		return (NULL);
	for (i = 0; node; node = node->next, i++)
	{
		str = malloc(_strlen(node->str) + 1);
		if (!str)
		{
			for (j = 0; j < i; j++)
				free(strs[j]);
			free(strs);
			return (NULL);
		}

		str = _strcpy(str, node->str);
		strs[i] = str;
	}
	strs[i] = NULL;
	return (strs);
}


/**
 * print_list - print all element of the list_t linked list
 * @e: the pointer for the first node
 *
 * Return: the size of the list
 */
size_t print_list(const list_t *e)
{
	size_t i = 0;

	while (e)
	{
		_puts(convert_number(e->num, 10, 0));
		_putchar(':');
		_putchar(' ');
		_puts(e->str ? e->str : "(nil)");
		_puts("\n");
		e = e->next;
		i++;
	}
	return (i);
}

/**
 * node_starts_with - return node whom string start with the prefix
 * @node: the pointer for the list head
 * @prefix: string match
 * @b: next characters after the prefix match
 *
 * Return: match the node or null
 */

list_t *node_starts_with(list_t *node, char *prefix, char b)
{
	char *q = NULL;

	while (node)
	{
		q = starts_with(node->str, prefix);
		if (q && ((b == -1) || (*q == b)))
			return (node);
		node = node->next;
	}
	return (NULL);
}

/**
 * get_node_index - get index of the node
 * @head: the pointer for the list head
 * @node: the pointer for the node
 *
 * Return: index for the node or else -1
 */
ssize_t get_node_index(list_t *head, list_t *node)
{
	size_t i = 0;

	while (head)
	{
		if (head == node)
			return (i);
		head = head->next;
		i++;
	}
	return (-1);
}

