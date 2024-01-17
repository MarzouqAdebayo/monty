#include "monty.h"

/**
 * handle_malloc_error - handles malloc error fails
 */
void handle_malloc_error(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	if (global_data.line)
		free(global_data.line);
	free_stack();
	exit(EXIT_FAILURE);
}

/**
 * handle_error - handles general error fails
 * @format: error text format
 */
void handle_error(const char *format, ...)
{
	va_list args;

	fprintf(stderr, "L%d: ", global_data.line_no);
	va_start(args, format);
	vfprintf(stderr, format, args);
	va_end(args);
	if (global_data.line)
		free(global_data.line);
	free_stack();
	exit(EXIT_FAILURE);
}

/**
 * free_stack -  frees stack
 */
void free_stack(void)
{
	stack_t *head, *current = global_data.head, *next;

	head = current;

	if (current)
	{
		while (current)
		{
			next = current->next;
			free(current);
			current = next;
		}
		free(head);
	}
}
