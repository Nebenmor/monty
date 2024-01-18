#include "monty.h"

/**
 * open_the_file - this functin helps open a file
 * @name_of_file: this is the file namepath
 * Return: void
 */

void open_the_file(char *name_of_file);
void open_the_file(char *name_of_file)
{
	FILE *fd = fopen(name_of_file, "r");

	if (name_of_file == NULL || fd == NULL)
		errors(2, name_of_file);

	read_the_file(fd);
	fclose(fd);
}


/**
 * read_the_file - this function reads a file
 * @fd: This is a pointer that points to a file descriptor
 * Return: void
 */

void read_the_file(FILE *fd);
void read_the_file(FILE *fd)
{
	int line_num, format = 0;
	char *buffer = NULL;
	size_t len = 0;

	for (line_num = 1; getline(&buffer, &len, fd) != -1; line_num++)
	{
		format = parse_the_line(buffer, line_num, format);
	}
	free(buffer);
}


/**
 * parse_the_line - This user-generated function separates each line
 * into tokens to determine which function should be called
 * @buffer: This is the line from the file
 * @line_num: This is the line number
 * @format:  This is the storage format.
 * If 0, Nodes will be entered as a stack.
 * if 1, nodes will be entered as a queue.
 * Return: Returns 0 if the opcode is stack. 1 if queue.
 */

int parse_the_line(char *buffer, int line_num, int format);
int parse_the_line(char *buffer, int line_num, int format)
{
	char *opcode, *value;
	const char *delim = "\n ";

	if (buffer == NULL)
		errors(4);

	opcode = strtok(buffer, delim);
	if (opcode == NULL)
		return (format);
	value = strtok(NULL, delim);

	if (strcmp(opcode, "stack") == 0)
		return (0);
	if (strcmp(opcode, "queue") == 0)
		return (1);

	find_the_function(opcode, value, line_num, format);
	return (format);
}

/**
 * find_the_function - This searches forthe appropriate function
 * for the opcode
 * @opcode: This is the opcode
 * @value: This is the argument of opcode
 * @format:  This is the storage format.
 * If 0, Nodes will be entered as a stack.
 * @ln: This is the line number
 * if 1 nodes will be entered as a queue.
 * Return: void
 */

void find_the_function(char *opcode, char *value, int ln, int format);
void find_the_function(char *opcode, char *value, int ln, int format)
{
	int i;
	int flag;

	instruction_t func_list[] = {
		{"push", addd_to_stack},
		{"pall", print_the_stack},
		{"pint", print_the_top},
		{"pop", pop_the_top},
		{"nop", nop},
		{"swap", swap_the_nodes},
		{"add", add_the_nodes},
		{"sub", sub_nodes_func},
		{"div", div_nodes_func},
		{"mul", mul_nodes_func},
		{"mod", mod_nodes_func},
		{"pchar", print_char_values},
		{"pstr", print_string},
		{"rotl", rotl_bottom},
		{"rotr", rotr_top},
		{NULL, NULL}
	};

	if (opcode[0] == '#')
		return;

	for (flag = 1, i = 0; func_list[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, func_list[i].opcode) == 0)
		{
			call_the_function(func_list[i].f, opcode, value, ln, format);
			flag = 0;
		}
	}
	if (flag == 1)
		errors(3, ln, opcode);
}


/**
 * call_the_function - This user-generated function calls the
 * required function.
 * @func: This is the pointer to the function that is about to be called
 * @op: This is a string that represents the opcode.
 * @val: This string represents a numeric value.
 * @ln: This is the line number for the instruction.
 * @format: This is the Format specifier.
 * If 0, Nodes will be entered as a stack.
 * if 1, nodes will be entered as a queue.
 */

void call_the_function(op_func func, char *op, char *val, int ln, int format);
void call_the_function(op_func func, char *op, char *val, int ln, int format)
{
	stack_t *node;
	int flag;
	int i;

	flag = 1;
	if (strcmp(op, "push") == 0)
	{
		if (val != NULL && val[0] == '-')
		{
			val = val + 1;
			flag = -1;
		}
		if (val == NULL)
			errors(5, ln);
		for (i = 0; val[i] != '\0'; i++)
		{
			if (isdigit(val[i]) == 0)
				errors(5, ln);
		}
		node = create_the_node(atoi(val) * flag);
		if (format == 0)
			func(&node, ln);
		if (format == 1)
			addd_to_queue(&node, ln);
	}
	else
		func(&head, ln);
}
