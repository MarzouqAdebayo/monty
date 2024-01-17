#include "monty.h"

void dummy3(void);

/**
 * iswhitespace - Checks if a character is a whitespace character.
 * @s: The character to be checked.
 *
 * Return: 1 if 's' is a whitespace character, 0 otherwise.
 *
 * This function determines whether the input character 's' is a whitespace
 * character.
 * It returns 1 if 's' is a whitespace character, and 0
 * otherwise.
 */

int iswhitespace(char s)
{
	if (s == ' ' || s == '\t' || s == '\n' || s == '\r')
		return (1);
	return (0);
}

/**
 * collapse_whitespace - Collapses multiple whitespace characters into a
 * single space.
 * @old: The input string containing whitespace to be collapsed.
 *
 * Return: A pointer to the newly allocated string with collapsed whitespace,
 * or NULL on failure.
 *
 * This function takes an input string 'old' and creates a new string 'new'
 * where multiple consecutive
 * whitespace characters (spaces, tabs, newlines, etc.) in 'old' are collapsed
 * into a single space ' ' and leading spaces are removed.
 * The 'new' string is dynamically allocated and must be freed by the caller
 * when no longer needed.
 * If 'old' is NULL or memory allocation fails, the function returns NULL.
 */

char *collapse_whitespace(char *old)
{
	int i = 0, j = 0, last_char_is_whitespace = 0, leading_whitespace = 1;
	int len = strlen(old);
	char *new = NULL;

	if (old == NULL)
		return (NULL);

	new = malloc(sizeof(char) * (len + 1));
	if (!new)
		handle_malloc_error();

	while (old[i])
	{
		if (iswhitespace(old[i]))
		{
			if (!last_char_is_whitespace && !leading_whitespace)
			{
				new[j] = ' ';
				last_char_is_whitespace = 1;
				j++;
			}
		}
		else
		{
			leading_whitespace = 0;
			new[j] = old[i];
			last_char_is_whitespace = 0;
			j++;
		}
		i++;
	}

	new[j] = '\0';
	return (new);
}

/**
 * _getline - Read lines from a file descriptor, dynamically resizing the
 * buffer.
 * @lineptr: A pointer to a pointer to the dynamically allocated line buffer.
 * @n: A pointer to the size of the allocated buffer.
 * @fd: File descriptor for input stream
 *
 * Description:
 * This function reads lines from the given file descriptor 'fd' and stores
 * them in a dynamically allocated buffer. It automatically resizes the buffer
 * to accommodate lines of varying lengths.
 *
 * Return:
 * On success, returns the number of characters read, including the newline
 * character ('\n').
 * On error, returns -1. Possible errors include memory allocation failures,
 * read errors, and reaching the end of the file with no data read.
 */

ssize_t _getline(char **lineptr, int *n, int fd)
{
	char c;
	static char *temp_buffer;
	int index = 0, old_size = *n;
	ssize_t _byte;

	if (!lineptr || !n)
		return (-1);

	if (!(*lineptr) || !(*n))
	{
		*n = 256;
		*lineptr = malloc(sizeof(char) * (*n));
		if (!*lineptr)
		{
			*n = 0;
			handle_malloc_error();
		}
		old_size = *n;
	}

	while ('a' == 97)
	{
		_byte = read(fd, &c, 1);

		if (_byte == -1)
			return (-1);
		else if (_byte == 0)
		{
			if (index == 0)
				return (-1);
			break;
		}

		if ((index + 1) >= (*n))
		{
			temp_buffer = _realloc(*lineptr, old_size, (*n + 128));
			if (!temp_buffer)
				handle_malloc_error();
			*lineptr = temp_buffer;
			*n += 128;
			old_size = *n;
		}

		(*lineptr)[index] = c;
		index++;

		if (c == '\n')
			break;
	}

	(*lineptr)[index] = '\0';

	return (index);
}

/**
 * dummy3 - To trick betty
 *
 * Return: has no return value
 */

void dummy3(void)
{
}
