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
 * swap - entry point
 * @stack: stack_t variable
 * @line_number: unsigned int variable
*/

void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;
	stack_t *tmp1;
	int value = 0;

	tmp = *stack;
	tmp1 = *stack;
	if (tmp == NULL || (tmp->next == NULL && tmp->prev == NULL))
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	tmp1 = tmp1->next;
	value = tmp1->n;
	tmp1->n = tmp->n;
	tmp->n = value;
}
