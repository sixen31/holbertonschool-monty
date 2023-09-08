#include "monty.h"

/**
 * _push - Pushes an element to the stack.
 * @stack: Double pointer to the head of the stack.
 * @line_number: Line number of the opcode.
 */
void _push(stack_t **stack, unsigned int line_number)
{
        char *arg = strtok(NULL, " \n\t\r");
        int n;

        if (!arg || !isdigit(*arg))
        {
                fprintf(stderr, "L%u: usage: push integer\n", line_number);
                exit(EXIT_FAILURE);
        }

        n = atoi(arg);

        add_node(stack, n); 
}
