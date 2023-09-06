#include "monty.h"

/**
 * main - Entry point for Monty bytecode interpreter.
 * @argc: Number of command line arguments.
 * @argv: Array of command line argument strings.
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure.
 */
int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    FILE *file = fopen(argv[1], "r");

    if (!file)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    // Lire le fichier ligne par ligne et exécuter les opcodes.

    fclose(file);
    free_all(); // Vous devrez implémenter cette fonction pour libérer les ressources.

    return EXIT_SUCCESS;
}
