#include "monty.h"

/**
 * mul_nodes_func - This function adds the top two elements of the stack.
 * @stack: Is a pointer to a pointer pointing to top node of the stack.
 * @line_num: This interger represent the line number of of the opcode.
 */

void mul_nodes_func(stack_t **stack, unsigned int line_num);
void mul_nodes_func(stack_t **stack, unsigned int line_num)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_errors(8, line_num, "mul");

	(*stack) = (*stack)->next;
	sum = (*stack)->n * (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}


/**
 * mod_nodes_func - This function adds the top two elements of the stack.
 * @stack: This is a pointer to a pointer pointing to top node of the stack.
 * @line_num: Is an interger representing the line number of of the opcode.
 */
void mod_nodes_func(stack_t **stack, unsigned int line_num)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)

		more_errors(8, line_num, "mod");


	if ((*stack)->n == 0)
		more_errors(9, line_num);
	(*stack) = (*stack)->next;
	sum = (*stack)->n % (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
