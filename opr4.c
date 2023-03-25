#include "monty.h"

/**
 * _pchar - prints the char at the top of the stack
 * @chari: ptr to ptr to stack
 * @l: line in the file
 */
void _pchar(stack_t ** chari, unsigned int l)
{
	int i;
	stack_t *tra;

	if (*chari == NULL)
	{
		dprintf(STDERR_FILENO, "L%u: can't pchar, stack empty\n", l);
		exit(EXIT_FAILURE);
	}
	tra = (*chari)->prev;
	i = tra->n;
	
	if ((i >= 65 && i <= 90) || (i >= 97 && i <= 122))
	{
		printf("%c\n", i);
	}
	else
	{
		dprintf(STDERR_FILENO, "L%u: can't pchar, value out of range\n", l);
		exit(EXIT_FAILURE);
	}

}
