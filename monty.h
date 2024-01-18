#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>

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
	void (*f)(stack_t **stack, unsigned int line_num);
} instruction_t;

extern stack_t *head;
typedef void (*op_func)(stack_t **, unsigned int);

/*file operations*/
void open_the_file(char *name_of_file);
int parse_the_line(char *buffer, int line_num, int format);
void read_the_file(FILE *);
int len_chars(FILE *);
void find_the_function(char *, char *, int, int);

/*Stack operations*/
stack_t *create_the_node(int n);
void free_the_nodes(void);
void print_the_stack(stack_t **, unsigned int);
void addd_to_stack(stack_t **, unsigned int);
void addd_to_queue(stack_t **, unsigned int);

void call_the_function(op_func, char *, char *, int, int);

void print_the_top(stack_t **, unsigned int);
void pop_the_top(stack_t **, unsigned int);
void nop(stack_t **, unsigned int);
void swap_the_nodes(stack_t **, unsigned int);

/*Math operations with nodes*/
void add_the_nodes(stack_t **, unsigned int);
void sub_nodes_func(stack_t **, unsigned int);
void div_nodes_func(stack_t **, unsigned int);
void mul_nodes_func(stack_t **, unsigned int);
void mod_nodes_func(stack_t **, unsigned int);

/*String operations*/
void print_char_values(stack_t **, unsigned int);
void print_string(stack_t **, unsigned int);
void rotl_bottom(stack_t **, unsigned int);

/*Error handling*/
void errors(int error_codes, ...);
void more_errors(int error_codes, ...);
void string_errors(int error_codes, ...);
void rotr_top(stack_t **, unsigned int);

#endif
