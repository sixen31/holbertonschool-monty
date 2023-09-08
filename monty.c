#include "monty.h"

/**
 * open_file - Opens the Monty bytecode file.
 * @filename: Name of the Monty bytecode file.
 * Return: A pointer to the opened file, or NULL on failure.
 */
FILE *open_file(const char *filename)
{
	FILE *file = fopen(filename, "r");

	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}

	return (file);
}

/**
 * close_file - Closes the Monty bytecode file.
 * @file: Pointer to the opened file.
 */
void close_file(FILE *file)
{
	fclose(file);
}

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}

	stack_t *stack = NULL;
	FILE *file = open_file(argv[1]);
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
			close_file(file);
			free_all(&stack);
			return (EXIT_FAILURE);
		}

		instruction->f(&stack, line_number);
	}

	free(line);
	close_file(file);
	free_all(&stack);
	return (EXIT_SUCCESS);
}
