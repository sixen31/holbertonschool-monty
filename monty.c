#include "monty.h"
#include <stdio.h>

/**
 * process_instruction - Traite une instruction Monty.
 * @stack: Pointeur vers le sommet de la pile.
 * @opcode: L'opcode de l'instruction.
 * @line_number: Le numéro de ligne de l'instruction.
 */
void process_instruction(
		stack_t **stack, char *opcode, unsigned int line_number)
{
	(void)stack;
	(void)opcode;
	(void)line_number;
}

/**
 * main - Point d'entrée pour l'interpréteur de bytecode Monty.
 * @argc: Nombre d'arguments de la ligne de commande.
 * @argv: Tableau de chaînes d'arguments de la ligne de commande.
 * Return: EXIT_SUCCESS en cas de succès, EXIT_FAILURE en cas d'échec.
 */
int main(int argc, char **argv)
{
	FILE *file = erreur(argc, argv);
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;
	unsigned int line_number = 0;
	stack_t *stack = NULL;

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
			free_stack(&stack);
			exit(EXIT_FAILURE);
		}

		process_instruction(&stack, opcode, line_number);
	}

	free(line);
	fclose(file);
	free_stack(&stack);
	return (EXIT_SUCCESS);
}
