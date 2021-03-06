#include "monty.h"

/**
 * pchar - print character from top of stack
 * @stack: double pointer to top of stack
 * @line_number: line number of current operation
 *
 * Return: void
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
	int ch;

	if (tmp == NULL)
	{
		fprintf(stderr,
			"L%u: can't pchar, stack empty\n",
			line_number);
		exit(EXIT_FAILURE);
	}
	ch = (*stack)->n;
	if (ch < 0 || ch > 127)
	{
		fprintf(stderr,
			"L%u: can't pchar, value out of range\n",
			line_number);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", ch);
}
