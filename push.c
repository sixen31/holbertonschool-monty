#include "monty.h"

/**
 * _push - Pushes an element to the stack.
 * @stack: Double pointer to the head of the stack.
 * @line_number: Line number of the opcode.
 */
void _push(stack_t **stack, unsigned int line_number)
{
    char *arg = strtok(NULL, " \n\t\r");
    int n, i;

    if (!arg)
    {
        fprintf(stderr, "L%u: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }

    for (i = 0; arg[i]; i++)
    {
        if (i == 0 && arg[i] == '-')
            continue;
        if (!isdigit(arg[i]))
        {
            fprintf(stderr, "L%u: usage: push integer\n", line_number);
            exit(EXIT_FAILURE);
        }
    }

    n = atoi(arg);

    add_node(stack, n);
}
