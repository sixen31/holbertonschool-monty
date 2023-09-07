#include "monty.h"

/**
 * _swap - Swaps the top two elements of the stack.
 * @stack: Double pointer to the head of the stack.
 * @line_number: Line number of the opcode.
 */
void _swap(stack_t **stack, unsigned int line_number)
{
	int tmp;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	tmp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = tmp;
}
