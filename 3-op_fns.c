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

/**
 * pchar_fn - prints a ascii char from stack
 */
void pchar_fn(void)
{
	if (!global_data.head)
		handle_error("can't pchar, stack empty\n");
	if (global_data.head->n >= 0 && global_data.head->n <= 127)
	{
		putchar(global_data.head->n);
		putchar('\n');
		return;
	}
	handle_error("can't pchar, value out of range\n");
}

/**
 * pstr_fn - print ascii string from stack values
 */
void pstr_fn(void)
{
	stack_t *current = global_data.head;

	while (current)
	{
		if (current->n >= 1 && current->n <= 127)
			putchar(current->n);
		else
			break;
		current = current->next;
	}
	putchar('\n');
}

/**
 * rotl_fn - rotates stack to the top
*/
void rotl_fn(void)
{
	stack_t *current = global_data.head, *holder;

	if (!current)
		return;

	if (current->next)
	{
		holder = global_data.head;
		global_data.head = holder->next;
		while (current->next)
			current = current->next;
		holder->prev = current;
		holder->next = NULL;
		current->next = holder;
		global_data.head->prev = NULL;
	}
}

/**
 * rotr_fn - rotates the stack to the bottom
 */
void rotr_fn(void)
{
	stack_t *current = global_data.head;

	if (!current)
		return;

	while (current->next)
		current = current->next;
	current->next = global_data.head;
	current->next->prev = current;
	current->prev->next = NULL;
	current->prev = NULL;
	global_data.head = current;
}
