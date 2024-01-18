#include "monty.h"

/**
 * errors - This function prints error messages based on their error code
 * @error_codes: These are the following error codes:
 * (1) => If the user provides none or more than one file to the program
 * (2) => If the file is unreadable or can't be opened
 * (3) => If the file the user provides contains invalid instructions
 * (4) => If the program cannot read malloc more memory
 * (5) => If the value assigned to "push" is not an integer
 * (6) => If the stack contains nothing for pint
 * (7) => If the stack contains nothing for pop
 * (8) => If the stack cannot operate because it's too short
 */

void errors(int error_codes, ...);
void errors(int error_codes, ...)
{
	va_list ag;
	char *opp;
	int l_number;

	va_start(ag, error_codes);
	switch (error_codes)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			fprintf(stderr, "Error: Can't open file %s\n",
				va_arg(ag, char *));
			break;
		case 3:
			l_number = va_arg(ag, int);
			opp = va_arg(ag, char *);
			fprintf(stderr, "L%d: unknown instruction %s\n", l_number, opp);
			break;
		case 4:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		case 5:
			fprintf(stderr, "L%d: usage: push integer\n", va_arg(ag, int));
			break;
		default:
			break;
	}
	free_the_nodes();
	exit(EXIT_FAILURE);
}

/**
 * more_errors - This handles the errors.
 * @error_codes: The error codes are as follows:
 * (6) => If the stack contains nothing for pint
 * (7) => If the stack contains nothinf for pop
 * (8) => If the stack cannot operate because it's too short
 * (9) => Rrepresents division by zero.
 */

void more_errors(int error_codes, ...);
void more_errors(int error_codes, ...)
{
	va_list ag;
	char *opp;
	int l_num;

	va_start(ag, error_codes);
	switch (error_codes)
	{
		case 6:
			fprintf(stderr, "L%d: can't pint, stack empty\n",
				va_arg(ag, int));
			break;
		case 7:
			fprintf(stderr, "L%d: can't pop an empty stack\n",
				va_arg(ag, int));
			break;
		case 8:
			l_num = va_arg(ag, unsigned int);
			opp = va_arg(ag, char *);
			fprintf(stderr, "L%d: can't %s, stack too short\n", l_num, opp);
			break;
		case 9:
			fprintf(stderr, "L%d: division by zero\n",
				va_arg(ag, unsigned int));
			break;
		default:
			break;
	}
	free_the_nodes();
	exit(EXIT_FAILURE);
}

/**
 * string_errors - This user generated function handles the errors.
 * @error_codes: The error codes are as follow:
 * (10) ~> If the number inside a node is outside the bounds of ASCIIs.
 * (11) ~> Is displayed if the stack is empty.
 */
void string_errors(int error_codes, ...)
{
	va_list ag;
	int l_number;

	va_start(ag, error_codes);
	l_number = va_arg(ag, int);
	switch (error_codes)
	{
		case 10:
			fprintf(stderr, "L%d: can't pchar, value out of range\n", l_number);
			break;
		case 11:
			fprintf(stderr, "L%d: can't pchar, stack empty\n", l_number);
			break;
		default:
			break;
	}
	free_the_nodes();
	exit(EXIT_FAILURE);
}
