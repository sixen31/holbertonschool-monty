#include "monty.h"

/**
 * free_stack - Frees a stack_t linked list.
 * @stack: Double pointer to the head of the stack.
 *
 * Description: This function frees all nodes in a stack_t linked list.
 * It takes a double pointer to the head of the stack and iterates through
 * the list, freeing each node's memory as it goes.
 */
void free_stack(stack_t **stack)
{
	stack_t *temp;

	if (!stack || !*stack)
		return;

	while (*stack)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
	}
}
