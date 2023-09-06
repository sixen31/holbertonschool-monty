#include "monty.h"

/**
 * get_instruction - Trouve la fonction correspondante pour une opcode.
 * @opcode: L'opcode à rechercher.
 * Return: Un pointeur vers la fonction correspondante, ou NULL si non trouvée.
 */
instruction_t *get_instruction(char *opcode)
{
    static instruction_t instructions[] = {
        {"push", _push},
        {"pall", _pall},
        {"pint", _pint},
        {"pop", _pop},
        {"swap", _swap},
        {"add", _add},
        {"nop", _nop},
        {NULL, NULL}
    };

    int i = 0;
    while (instructions[i].opcode)
    {
        if (strcmp(instructions[i].opcode, opcode) == 0)
            return &(instructions[i]);
        i++;
    }

    return NULL; // Opcode non trouvé
}
