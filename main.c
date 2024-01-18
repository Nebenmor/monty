#include "monty.h"
stack_t *head = NULL;

/**
 * main - This is the entry point
 * @argc: This is the argument count
 * @argv: This is the list of arguments
 * Return: always 0
 */

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	open_the_file(argv[1]);
	free_the_nodes();
	return (0);
}

/**
 * create_the_node: This user-generated function creates a node.
 * @n: This is the number to be inputed to the node.
 * Return: Upon sucess a pointer to the node. Otherwise NULL.
 */

stack_t *create_the_node(int n)
{
	stack_t *node;

	node = malloc(sizeof(stack_t));
	if (node == NULL)
		errors(4);
	node->next = NULL;
	node->prev = NULL;
	node->n = n;
	return (node);
}


/**
 * free_the_nodes - This function frees nodes in the stack.
 */

stack_t *tmp;

void free_the_nodes(void)
{
	if (head == NULL)
		return;

	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}


/**
 * addd_to_the_queue - This function adds a node to the queue.
 * @new_node: This is the pointer to the new node.
 * @ln: line number of the opcode
 */


void addd_to_queue(stack_t **new_node, __attribute__((unused))unsigned int ln)
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
	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = *new_node;
	(*new_node)->prev = tmp;

}
