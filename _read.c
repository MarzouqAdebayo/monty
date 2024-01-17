#include "monty.h"

/**
 * _read_fn - Read a line of input from standard input.
 * @fd: file descriptor
 *
 * Return: A pointer to the read line (including the newline character),
 *         or NULL on failure or end of file.
 *
 * This function reads a line of input from the standard input (stdin).
 * It dynamically allocates memory to store the input line and automatically
 * resizes it as needed.
 * The function returns a pointer to the read line, including the newline
 * character at the end. If an error occurs or the end of file is reached,
 * it returns NULL and may exit the program with an error code.
 */

void _read_fn(int fd)
{
	char *line = NULL;
	int len = 0;
	ssize_t bytes_read = 0;

	bytes_read = _getline(&line, &len, fd);
	if (bytes_read == -1)
	{
		if (line)
			free(line);
		free_stack();
		exit(EXIT_SUCCESS);
	}
	global_data.line = collapse_whitespace(line);
	free(line);
	global_data.line_no++;
	global_data.opcode = strtok(global_data.line, " ");
	global_data.op_val = strtok(NULL, " ");
	run();
	free(global_data.line);
}
