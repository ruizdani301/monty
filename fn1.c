#include "monty.h"


/**
 * push - entry point
 * @stack: stack_t variable
 * @number: int variable
*/

void push(stack_t **stack, unsigned int number)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		freestack(stack);
		exit(EXIT_FAILURE);
	}

	new->n = number;
	new->prev = NULL;
	new->next = *stack;
	if (*stack != NULL)
		(*stack)->prev = new;
	*stack = new;
}

/**
 * pall - entry point
 * @stack: stack_t variable
 * @line_number: unsigned int variable
*/

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;
	(void)line_number;

	tmp = *stack;
	if (tmp == NULL)
		return;
	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}

/**
 * pint - entry point
 * @stack: stack_t variable
 * @line_number: unsigned int variable
*/

void pint(stack_t **stack, unsigned int line_number)
{

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

/**
 * nop - entry point
 * @stack: stack_t variable
 * @line_number: unsigned int variable
*/

void nop(stack_t **stack, unsigned int line_number)
{
	stack = stack;
	line_number = line_number;
}

/**
 * swap - swaps the top two elements of the stack.
 * @stack: struct stack_t
 * @line_number: line number to show in error case
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
	stack_t *tmp1 = *stack;
	int save = 0;

	if ((tmp == NULL) || (tmp->next == NULL))
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	tmp1 = tmp1->next;
	save = tmp1->n;
	tmp1->n = tmp->n;
	tmp->n = save;
}
