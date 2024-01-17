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
		{"swap", swap_fn},
		{"add", add_fn},
		{"nop", nop_fn},
		{"sub", sub_fn},
		{"div", div_fn},
		{"mul", mul_fn},
		{"mod", mod_fn},
		{NULL, NULL}};

	if (!command || command[0] == '#')
		return;
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
