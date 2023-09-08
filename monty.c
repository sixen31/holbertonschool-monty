#include "monty.h"
#include <stdio.h>

stack_t *stack = NULL;

int main(int argc, char **argv)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;
	unsigned int line_number = 0;
	FILE *file = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = erreur(argc, argv); // Utilisation de la fonction correctement nommée erreur

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
