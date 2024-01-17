#include "monty.h"

/**
 * push_fn - pushes a value on to the stack
 */
void push_fn(void)
{
	stack_t *new;
	int val;

	if (isdigits(global_data.op_val) == 0)
		handle_error("usage: push integer\n");

	val = atoi(global_data.op_val);
	new = malloc(sizeof(stack_t));
	if (!new)
		handle_malloc_error();
	new->n = val;
	new->next = global_data.head;
	new->prev = NULL;
	if (global_data.head)
		global_data.head->prev = new;
	global_data.head = new;
}

/**
 * pall_fn - prints values in stack from top to bottom
 */
void pall_fn(void)
{
	stack_t *current = global_data.head;

	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

/**
 * pint_fn - prints the value at the top of the stack
 */
void pint_fn(void)
{
	stack_t *current = global_data.head;

	if (!current)
		handle_error("can't pint, stack empty\n");
	printf("%d\n", current->n);
}

/**
 * pop_fn - removes the value at the top of the stack
 */
void pop_fn(void)
{
	stack_t *current = global_data.head;

	if (!current)
		handle_error("can't pop an empty stack\n");
	global_data.head = current->next;

	if (global_data.head)
		global_data.head->prev = NULL;
	free(current);
}

/**
 * swap_fn - swaps the top two values on the stack
 */
void swap_fn(void)
{
	stack_t *head = global_data.head;
	int holder;

	if (!head || !head->next)
		handle_error("can't swap, stack too short");
	holder = head->n;
	head->n = head->next->n;
	head->next->n = holder;
}
