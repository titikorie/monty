#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

/**
 * push - add node to the stack
 * @stack: stack given by main
 * @counter: line_number
 *
 * Return: void
 */
void push(stack_t **stack, unsigned int counter)
{
	char *n = global.argument;

	if ((is_digit(n)) == 0)
	{
		fprintf(stderr, "L%d: usage: push integer\n", counter);
		exit(EXIT_FAILURE);
	}

	if (global.data_struct == 1)
	{
		if (!add_node(stack, atoi(global.argument)))
		{
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		if (!queue_node(stack, atoi(global.argument)))
		{
			exit(EXIT_FAILURE);
		}
	}
}
