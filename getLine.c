#include "shell.h"

/**
 * input_buf - buffer the chained commands
 * @info: the parameter struct
 * @buf: the address of the buffer
 * @len: address of the len var
 *
 * Return: the bytes read
 */
ssize_t input_buf(info_t *info, char **buf, size_t *len)
{
	ssize_t x = 0;
	size_t len_q = 0;

	if (!*len) /* if nothing left in the buffer, fill it */
	{
		/*bfree((void **)info->cmd_buf);*/
		free(*buf);
		*buf = NULL;
		signal(SIGINT, sigintHandler);
#if USE_GETLINE
		x = getline(buf, &len_q, stdin);
#else
		x = _getline(info, buf, &len_q);
#endif
		if (x > 0)
		{
			if ((*buf)[x - 1] == '\n')
			{
				(*buf)[x - 1] = '\0'; /* remove trailing newline */
				x--;
			}
			info->linecount_flag = 1;
			remove_comments(*buf);
			build_history_list(info, *buf, info->histcount++);
			/* if (_strchr(*buf, ';')) is this a command chain? */
			{
				*len = x;
				info->cmd_buf = buf;
			}
		}
	}
	return (x);
}

/**
 * get_input - get line and minus the newline
 * @info: the parameter struct
 *
 * Return: the bytes read
 */
ssize_t get_input(info_t *info)
{
	static char *buf; /* the ';' command chain buffer */
	static size_t i, j, len;
	ssize_t x = 0;
	char **buf_q = &(info->arg), *q;

	_putchar(BUF_FLUSH);
	x = input_buf(info, &buf, &len);
	if (x == -1) /* EOF */
		return (-1);
	if (len) /* we have commands left in the chain buffer */
	{
		j = i; /* init new iterator to current buf position */
		q = buf + i; /* get pointer for return */

		check_chain(info, buf, &j, i, len);
		while (j < len) /* iterate to semicolon or end */
		{
			if (is_chain(info, buf, &j))
				break;
			j++;
		}

		i = j + 1; /* increment past nulled ';'' */
		if (i >= len) /* reached end of buffer? */
		{
			i = len = 0; /* reset position and length */
			info->cmd_buf_type = CMD_NORM;
		}

		*buf_q = q; /* pass back pointer to current command position */
		return (_strlen(q)); /* return length of current command */
	}

	*buf_q = buf; /* else not a chain, pass back buffer from _getline() */
	return (x); /* return length of buffer from _getline() */
}

/**
 * read_buf - read the buffer
 * @info: the parameter struct
 * @buf: the buffer
 * @i: the size
 *
 * Return: x
 */
ssize_t read_buf(info_t *info, char *buf, size_t *i)
{
	ssize_t x = 0;

	if (*i)
		return (0);
	x = read(info->readfd, buf, READ_BUF_SIZE);
	if (x >= 0)
		*i = x;
	return (x);
}

/**
 * _getline - get next line of the input from STDIN
 * @info: the parameter struct
 * @ptr: address of the pointer to buffer, prepositioned or NULL
 * @length: the size of the prepositioned to buffer if not NULL
 *
 * Return: w
 */
int _getline(info_t *info, char **ptr, size_t *length)
{
	static char buf[READ_BUF_SIZE];
	static size_t i, len;
	size_t k;
	ssize_t x = 0, w = 0;
	char *q = NULL, *new_q = NULL, *b;

	q = *ptr;
	if (q && length)
		w = *length;
	if (i == len)
		i = len = 0;

	x = read_buf(info, buf, &len);
	if (x == -1 || (x == 0 && len == 0))
		return (-1);

	b = _strchr(buf + i, '\n');
	k = b ? 1 + (unsigned int)(b - buf) : len;
	new_q = _realloc(q, w, w ? w + k : k + 1);
	if (!new_q) /* MALLOC FAILURE! */
		return (q ? free(q), -1 : -1);

	if (w)
		_strncat(new_q, buf + i, k - i);
	else
		_strncpy(new_q, buf + i, k - i + 1);

	w += k - i;
	i = k;
	q = new_q;

	if (length)
		*length = w;
	*ptr = q;
	return (w);
}

/**
 * sigintHandler - block the ctrl-C
 * @sig_num: signal number
 *
 * Return: the void
 */
void sigintHandler(__attribute__((unused))int sig_num)
{
	_puts("\n");
	_puts("$ ");
	_putchar(BUF_FLUSH);
}

