#include "monty.h"

/**
 * add - add the first two values in the stack
*/
void add_fn(void)
{
	stack_t *head = global_data.head;
	int sum;

	if (!head || !head->next)
		handle_error("can't add, stack too short\n");
	sum = head->n + head->next->n;
	head->next->n = sum;
	global_data.head = head->next;
	free(head);
}

/**
 * nop_fn - does nothing
*/
void nop_fn(void)
{
	return;
}

/**
 * sub - subtract the first value from the second in the stack
*/
void sub_fn(void)
{
	stack_t *head = global_data.head;
	int sub;

	if (!head || !head->next)
		handle_error("can't add, stack too short\n");
	sub = head->next->n - head->n;
	head->next->n = sub;
	global_data.head = head->next;
	free(head);
}
