#include "monty.h"


/**
 * add_to_the_stack - This function adds a node to the stack.
 * @new_node: This is a pointer to the new node.
 * @ln: This is an interger that represents the line number of the opcode.
 */

void addd_to_stack(stack_t **new_node, __attribute__((unused))unsigned int ln);
void addd_to_stack(stack_t **new_node, __attribute__((unused))unsigned int ln)
{
	stack_t *tmp;

	if (new_node == NULL || *new_node == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *new_node;
		return;
	}
	tmp = head;
	head = *new_node;
	head->next = tmp;
	tmp->prev = head;
}


/**
 * print_the_stack - This function adds a node to the stack.
 * @stack: Is a pointer to a pointer that points to the top node of the stack.
 * @line_num: line number of the opcode.
 */

void print_the_stack(stack_t **stack, unsigned int line_num);
void print_the_stack(stack_t **stack, unsigned int line_num)
{
	stack_t *tmp;

	(void) line_num;
	if (stack == NULL)
		exit(EXIT_FAILURE);
	tmp = *stack;
	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}

/**
 * pop_the_top - This fuction adds a node to the stack.
 * @stack: This is a pointer to a pointer that points to top node of the stack.
 * @line_num: This integer represents the line number of of the opcode.
 */

void pop_the_top(stack_t **stack, unsigned int line_num);
void pop_the_top(stack_t **stack, unsigned int line_num)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL)
		more_errors(7, line_num);

	tmp = *stack;
	*stack = tmp->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(tmp);
}

/**
 * print_the_top - This function prints the top node of the stack.
 * @stack: A pointer to a pointer pointing to the top node of the stack.
 * @line_num: An interger representing the line number of of the opcode.
 */
void print_the_top(stack_t **stack, unsigned int line_num)
{
	if (stack == NULL || *stack == NULL)
		more_errors(6, line_num);
	printf("%d\n", (*stack)->n);
}
