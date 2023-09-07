#include "monty.h"

stack_t *stack = NULL;

/**
 * main - Entry point for Monty bytecode interpreter.
 * @argc: Number of command line arguments.
 * @argv: Array of command line argument strings.
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure.
 */
int main(int argc, char **argv)

	char *line = NULL;
	size_t len = 0;
	ssize_t nread;
	unsigned int line_number = 0;
	FILE *file = NULL;

	file = erreur(argc, argv);
while ((nread = getline(&line, &len, file)) != -1)
{
	line_number++;
	char *opcode = strtok(line, " \n\t\r");

	if (!opcode || *opcode == '#')
		continue;

	instruction_t *instruction = get_instruction(opcode);

	if (!instruction)
	{
		fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
		free(line);
		fclose(file);
		free_all();
		exit(EXIT_FAILURE);
	}

	instruction->f(&stack, line_number);
}

free(line);
fclose(file);
free_all();
return (EXIT_SUCCESS);
}
