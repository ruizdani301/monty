#include "monty.h"

/**
 * rotl - turn top to the last in the stack.
 * @stack: struct stack_t
 * @line_number: line number to show in error case
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	if ((tmp == NULL) || (tmp->next == NULL))
	{
		return;
	}
	(void)line_number;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	tmp->next = *stack;
	*stack = (*stack)->next;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
	tmp->next->prev = tmp;
	tmp = tmp->next;
}
