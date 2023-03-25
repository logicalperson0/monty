#include "monty.h"

/**
 * _pchar - prints the char at the top of the stack
 * @chari: ptr to ptr to stack
 * @l: line in the file
 */
void _pchar(stack_t ** chari, unsigned int l)
{
	int i;
	stack_t *tra = *chari;

	if (*chari == NULL)
	{
		dprintf(STDERR_FILENO, "L%u: can't pchar, stack empty\n", l);
		exit(EXIT_FAILURE);
	}
	i = tra->n;
	
	if (!isascii(i))
	{
		dprintf(STDERR_FILENO, "L%u: can't pchar, value out of range\n", l);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", i);

}
