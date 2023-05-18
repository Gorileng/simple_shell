#include "shell.h"

/**
 * bfree - free the pointer & NULLs the address
 * @ptr: address the pointer to free
 *
 * Return: 1 freed, or else 0.
 */
int bfree(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}

