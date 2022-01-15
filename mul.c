#include "monty.h"

/**
 * mul - multiply top two elements of stack and push result
 * @stack: double pointer to head of stack
 * @line_number: line number of current operation
 *
 * Return: void
 */
void mul(stack_t **stack, unsigned int line_number)
{
    stack_t *tmp = *stack;
	int n;

	if ((tmp == NULL) || (tmp->next == NULL))
	{
		fprintf(stderr,
			"L%u: can't mul, stack too short\n",
			line_number);
		exit(EXIT_FAILURE);
	}
	n = (*stack)->n;
	pop(stack, line_number);
	(*stack)->n *= n;
}