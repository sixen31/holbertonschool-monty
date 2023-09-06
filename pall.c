#include "monty.h"

/**
 * _pall - Prints all the values on the stack.
 * @stack: Double pointer to the head of the stack.
 * @line_number: Line number of the opcode.
 */
void _pall(stack_t **stack, unsigned int line_number)
{
    (void)line_number;

    print_stack(*stack);
}
