#include "monty.h"

/**
 * free_all - Libère la mémoire de la pile et ferme le fichier d'entrée.
 * @stack: Double pointer to the head of the stack.
 */
void free_all(stack_t **stack)
{
	if (stack)
		free_stack(stack);
}
