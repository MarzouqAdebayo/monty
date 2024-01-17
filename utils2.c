#include "monty.h"

/**
 * _realloc - Reallocate memory for a previously allocated block.
 *
 * @ptr: A pointer to the previously allocated memory block.
 * @old_size: The old size (in bytes) for the memory block.
 * @new_size: The new size (in bytes) for the memory block.
 *
 * Return: If successful, a pointer to the newly allocated memory block
 * NULL on failure.
 */

void *_realloc(void *ptr, int old_size, int new_size)
{
	char *new = NULL, *cast_ptr = ptr;
	int i, max = new_size > old_size ? old_size : new_size;

	if (!ptr && !new_size)
		return (NULL);
	if (!ptr && new_size)
	{
		new = malloc(new_size);
		if (!new)
			return (NULL);
		return (new);
	}
	if (ptr && !new_size)
	{
		free(ptr);
		return (NULL);
	}
	if (old_size == new_size)
		return (ptr);
	new = malloc(new_size);
	if (!new)
		return (NULL);
	for (i = 0; i < max; i++)
		*(new + i) = *(cast_ptr + i);
	free(ptr);

	return (new);
}

/**
 * isdigits - checks if a string contains only digits
 * @str: string to be checked
 *
 * Return: 1 if isdigits and 0 if not digits
 */
int isdigits(const char *str)
{
	while (*str != '\0')
	{
		if (!isdigit(*str))
		{
			return (0);
		}
		str++;
	}
	return (1);
}
