#include "monty.h"

/**
 * pstr - turn the list;
 * @stack: head (stack) to the stack;
 * @line_number: line number where opcode is located
 */

void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
	int str;

	(void)line_number;
	while (tmp != NULL)
	{
		str = tmp->n;
		if (str > 0 && str <= 127)
		{
			putchar(str);
		}
		else
		{
			break;
		}
		tmp = tmp->next;
	}
	putchar(10);
}
