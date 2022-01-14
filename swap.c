#include "monty.h"
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
		fprintf(stderr, "L%d: can't swap, stack too short\n",
			line_number);
		exit(EXIT_FAILURE);
	}

	tmp1 = tmp1->next;
	save = tmp1->n;
	tmp1->n = tmp->n;
	tmp->n = save;
}
