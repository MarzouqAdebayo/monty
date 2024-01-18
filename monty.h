#ifndef MONTY_H
#define MONTY_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <fcntl.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(void);
} instruction_t;

/**
 * struct data_s - global data for functions to access
 * @fd: file descriptor
 * @opcode: the opcode
 * @op_val: argument to opcode
 * @line: command line
 * @line_no: command line number
 * @head: head node of the stack
 *
 * Description: global data and the stack
 */
typedef struct data_s
{
	int fd;
	char *opcode;
	char *op_val;
	char *line;
	unsigned int line_no;
	stack_t *head;
} data_t;

extern data_t global_data;

void initialize_global_data(void);
void _read_fn(void);
void run(void);
ssize_t _getline(char **lineptr, int *n, int fd);
char *collapse_whitespace(char *old);
void handle_error(const char *format, ...);
void handle_malloc_error(void);
void *_realloc(void *ptr, int old_size, int new_size);
void free_stack(void);
int iswhitespace(char s);
int iscomment(const char *str);
int isdigits(const char *str);
void push_fn(void);
void pall_fn(void);
void pint_fn(void);
void pop_fn(void);
void swap_fn(void);
void add_fn(void);
void nop_fn(void);
void sub_fn(void);
void div_fn(void);
void mul_fn(void);
void mod_fn(void);
void pchar_fn(void);
void pstr_fn(void);
void rotl_fn(void);
void rotr_fn(void);

#endif
