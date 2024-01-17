#include "monty.h"

/**
 * run - checks and executes opcode
 */
void run(void)
{
	char *command = global_data.opcode;
	int i;
	instruction_t instr[] = {
		{"push", push_fn},
		{"pall", pall_fn},
		{"pint", pint_fn},
		{"pop", pop_fn},
		{NULL, NULL}};

	if (command == NULL)
		handle_error("no instruction provided\n");
	else if (command[0] == '#')
		handle_error("command starts with #\n");
	for (i = 0; instr[i].opcode; i++)
	{
		if (!strcmp(instr[i].opcode, command))
		{
			instr[i].f();
			return;
		}
	}
	handle_error("unknown instruction %s\n", command);
}
