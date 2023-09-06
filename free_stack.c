#include "monty.h"

/**
 * free_stack - Frees a stack_t linked list.
 * @stack: Double pointer to the head of the stack.
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
