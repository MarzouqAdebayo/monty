#include "monty.h"

/**
 * mod_fn - modulo of the second value by the first in the stack
 */
void mod_fn(void)
{
	stack_t *head = global_data.head;
	int mod;

	if (!head || !head->next)
		handle_error("can't mod, stack too short\n");
	if (head->n == 0)
		handle_error("division by zero\n");
	mod = head->next->n % head->n;
	head->next->n = mod;
	global_data.head = head->next;
	free(head);
}
