#include "monty.h"

/**
 * print_char_values - This prints the Ascii value.
 * @stack: Is a pointer to a pointer pointing to top node of the stack.
 * @line_num: Is an interger representing the line number of of the opcode.
 */

void print_char_values(stack_t **stack, unsigned int line_num);
void print_char_values(stack_t **stack, unsigned int line_num)
{
	int ascii;

	if (stack == NULL || *stack == NULL)
		string_errors(11, line_num);

	ascii = (*stack)->n;
	if (ascii < 0 || ascii > 127)
		string_errors(10, line_num);

	printf("%c\n", ascii);
}

/**
 * print_string - This function prints a string.
 * @stack: This is a pointer to a pointer pointing to top node of the stack.
 * @ln: Is an interger representing the line number of the opcode.
 */

void print_string(stack_t **stack, __attribute__((unused))unsigned int ln);
void print_string(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	int ascii;
	stack_t *tmp;

	if (stack == NULL || *stack == NULL)
	{
		printf("\n");
		return;
	}

	tmp = *stack;
	while (tmp != NULL)
	{
		ascii = tmp->n;
		if (ascii <= 0 || ascii > 127)
			break;
		printf("%c", ascii);
		tmp = tmp->next;
	}
	printf("\n");
}



/**
 * rotl_bottom - A function rotates the first node of the stack to the bottom
 * @stack: This is a  pointer to a pointer pointing to top node of the stack.
 * @ln: This is an interger representing the line number of of the opcode.
 */

void rotl_bottom(stack_t **stack, __attribute__((unused))unsigned int ln);
void rotl_bottom(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	tmp = *stack;
	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = *stack;
	(*stack)->prev = tmp;
	*stack = (*stack)->next;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}


/**
 * rotr_top - Function that rotates the last node of the stack to the top.
 * @stack: Is a Pointer to a pointer pointing to top node of the stack.
 * @ln: Is an Interger representing the line number of the opcode.
 */

void rotr_top(stack_t **stack, __attribute__((unused))unsigned int ln);
void rotr_top(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	tmp = *stack;

	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = *stack;
	tmp->prev->next = NULL;
	tmp->prev = NULL;
	(*stack)->prev = tmp;
	(*stack) = tmp;
}
