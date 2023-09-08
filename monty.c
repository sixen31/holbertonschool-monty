#include "monty.h"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		fprintf(stderr, "Usage: monty file\n");
		return (EXIT_FAILURE);
	}

	stack_t *stack = NULL;
	FILE *file = fopen(argv[1], "r");

	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;
	unsigned int line_number = 0;

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
			free_all(&stack)
				return (EXIT_FAILURE);
		}

		instruction->f(&stack, line_number);
	}
	free(line);
	fclose(file);
	free_all(&stack);
	return (EXIT_SUCCESS);
}
