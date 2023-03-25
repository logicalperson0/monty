#include "monty.h"

/**
 * chk_func - chk if opr is a valid opr
 * @opr: operator to chk
 * @head: ptr to ptr to beginning of the stack
 * @n: line num
 */
void chk_func(char *opr, stack_t **head, unsigned int n)
{
	size_t y;
	instruction_t oprs[] = {
		{"push", push},
		{"pall", pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"add", _add},
		{"nop", _nop},
		{"sub", _sub},
		{"div", div_},
		{"mul", multi},
		{"mod", _mod},
		{NULL, NULL}
	};

	for (y = 0; oprs[y].opcode != NULL; y++)
	{
		if (strcmp(oprs[y].opcode, opr) == 0)
		{
			oprs[y].f(head, n);
			return;
		}
	}
	dprintf(STDERR_FILENO, "L%u: unknown instruction %s\n", n, opr);
	exit(EXIT_FAILURE);
}
