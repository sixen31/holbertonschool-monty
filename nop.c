#include "monty.h"

/**
 * _nop - Doesn't do anything.
 * @stack: Double pointer to the head of the stack.
 * @line_number: Line number of the opcode.
 */
void _nop(stack_t **stack, unsigned int line_number)
{
    (void)stack;
    (void)line_number;
}
