#include "monty.h"

data_t global_data;

/**
 * initialize_global_data - sets the global data and stack
 */
void initialize_global_data(void)
{
	global_data.opcode = NULL;
	global_data.op_val = NULL;
	global_data.line = NULL;
	global_data.line_no = 0;
	global_data.head = NULL;
}

/**
 * main - entry function into the program
 * @argc: count of command line arguments passed
 * @argv: command line arguments passed
 *
 * Return: Always 0
 */
int main(int argc, char **argv)
{
	initialize_global_data();

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		free_stack();
		exit(EXIT_FAILURE);
	}
	global_data.fd = open(argv[1], O_RDONLY);
	if (global_data.fd == -1)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		free_stack();
		exit(EXIT_FAILURE);
	}

	while (1)
		_read_fn();

	return (0);
}
