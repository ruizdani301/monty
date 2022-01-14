#include "monty.h"

/**
 * sub - subs the top two elements of the stack.
 * @stack: head (stack) to the stack;
 * @line_number: line number where opcode is located
 */

void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
	int n = 0;

	if ((tmp == NULL) || (tmp->next == NULL))
	{
		fprintf(stderr,
			"L%u: can't sub, stack too short\n",
			line_number);
		exit(EXIT_FAILURE);
	}

	n = (*stack)->n;
	pop(stack, line_number);
	(*stack)->n -= n;
}
