#include "shell.h"

/**
 * _memset - fill the memory with constant byte
 * @w: pointer to memory area
 * @v: byte that fill *w with
 * @n: amount of bytes that are to be filled
 * Return: (w) pointer to memory area w
 */
char *_memset(char *w, char v, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		w[i] = v;
	return (w);
}

/**
 * ffree - free string of strings
 * @qq: the string of strings
 */
void ffree(char **qq)
{
	char **a = qq;

	if (!qq)
		return;
	while (*qq)
		free(*qq++);
	free(a);
}

/**
 * _realloc - it reallocate the block of the memory
 * @ptr: the pointer to the previous malloc'ated block
 * @old_size: the byte size of the previous block
 * @new_size: the byte size of the new block
 *
 * Return: the pointer to the da ol'block nameen.
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *q;

	if (!ptr)
		return (malloc(new_size));
	if (!new_size)
		return (free(ptr), NULL);
	if (new_size == old_size)
		return (ptr);

	q = malloc(new_size);
	if (!q)
		return (NULL);

	old_size = old_size < new_size ? old_size : new_size;
	while (old_size--)
		q[old_size] = ((char *)ptr)[old_size];
	free(ptr);
	return (q);
}

