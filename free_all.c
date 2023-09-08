#include "monty.h"

/**
 * free_all - Libère la mémoire de la pile et ferme le fichier d'entrée.
 */
void free_all(void)
{
	if (stack)
		free_stack(&stack);
}
