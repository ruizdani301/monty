#include "monty.h"

/**
 * pop - entry point
 * @stack: stack_t variable
 * @line_number: unsigned int variable
*/

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	tmp = *stack;
	if ((tmp) == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	if (tmp->next == NULL)
	{
		free(tmp);
		(*stack) = NULL;
	}
	(*stack) = (*stack)->next;
	(*stack)->prev = NULL;
	free(tmp);
}

/**
 * freestack - enrty point
 * @stack: stack_t variable
*/

void freestack(stack_t **stack)
{
	stack_t *tmp;

	while ((*stack) != NULL)
	{
		tmp = (*stack);
		(*stack) = (*stack)->next;
		free(tmp);
	}
}

/**
 * _isdigit - function that checks for a digit (0 through 9)..
 * @c: digit
 * Return:Returns 1 when c is a digit and 0 otherwise
 */

int _isdigit(int c)
{
	if (c >= 48 && c <= 57)
	{
		return (1);
	}
	return (0);
}
