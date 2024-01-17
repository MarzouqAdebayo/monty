#include "monty.h"

/**
 * add_fn - add the first two values in the stack
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
{}

/**
 * sub - subtract the first value from the second in the stack
*/
void sub_fn(void)
{
	stack_t *head = global_data.head;
	int sub;

	if (!head || !head->next)
		handle_error("can't sub, stack too short\n");
	sub = head->next->n - head->n;
	head->next->n = sub;
	global_data.head = head->next;
	free(head);
}

/**
 * div_fn - divides the second value by the first in the stack
 */
void div_fn(void)
{
	stack_t *head = global_data.head;
	int div;

	if (!head || !head->next)
		handle_error("can't div, stack too short\n");
	if (head->n == 0)
		handle_error("division by zero\n");
	div = head->next->n / head->n;
	head->next->n = div;
	global_data.head = head->next;
	free(head);
}

/**
 * mul_fn - multiplies the second value by the first in the stack
 */
void mul_fn(void)
{
	stack_t *head = global_data.head;
	int mul;

	if (!head || !head->next)
		handle_error("can't mul, stack too short\n");
	mul = head->next->n * head->n;
	head->next->n = mul;
	global_data.head = head->next;
	free(head);
}
