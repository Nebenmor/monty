#include "monty.h"

/**
 * nop - This doesn not do anything
 * @stack: Is a pointer to a pointer pointing to top node of the stack.
 * @line_num: An interger representing the line number of of the opcode.
 */
void nop(stack_t **stack, unsigned int line_num)
{
	(void)stack;
	(void)line_num;
}


/**
 * swap_the_nodes - This function swaps the top two elements of the stack.
 * @stack: A pointer to a pointer pointing to top node of the stack.
 * @line_num: An interger representing the line number of of the opcode.
 */

void swap_the_nodes(stack_t **stack, unsigned int line_num);
void swap_the_nodes(stack_t **stack, unsigned int line_num)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_errors(8, line_num, "swap");
	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	if (tmp->next != NULL)
		tmp->next->prev = *stack;
	tmp->next = *stack;
	(*stack)->prev = tmp;
	tmp->prev = NULL;
	*stack = tmp;
}

/**
 * add_the_nodes - This function adds the top two elements of the stack
 * @stack: Is a pointer to a pointer pointing to top node of the stack.
 * @line_num: Is an interger representing the line number of of the opcode.
 */

void add_the_nodes(stack_t **stack, unsigned int line_num);
void add_the_nodes(stack_t **stack, unsigned int line_num)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_errors(8, line_num, "add");

	(*stack) = (*stack)->next;
	sum = (*stack)->n + (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}


/**
 * sub_nodes_func - Function that adds the top two elements of the stack.
 * @stack: This is a pointer to a pointer pointing to top node of the sta
 * @line_num: Is an interger representing the line number of of the opcode.
 */

void sub_nodes_func(stack_t **stack, unsigned int line_num);
void sub_nodes_func(stack_t **stack, unsigned int line_num)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)

		more_errors(8, line_num, "sub");


	(*stack) = (*stack)->next;
	sum = (*stack)->n - (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}


/**
 * div_nodes - Adds the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_num: Interger representing the line number of of the opcode.
 */

void div_nodes_func(stack_t **stack, unsigned int line_num);
void div_nodes_func(stack_t **stack, unsigned int line_num)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_errors(8, line_num, "div");

	if ((*stack)->n == 0)
		more_errors(9, line_num);
	(*stack) = (*stack)->next;
	sum = (*stack)->n / (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
