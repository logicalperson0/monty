#include "monty.h"

/**
 * _sub - func that subtracts the top element of the stack
 * from the second top element of the stack
 * @stk: ptr to ptr to stack
 * @x: line in the file
 */
void _sub(stack_t **stk, unsigned int x)
{
	int sub = 0;

	if (glo.lens < 2)
	{
		dprintf(STDERR_FILENO, "L%u: can't sub, stack too short\n", x);
		exit(EXIT_FAILURE);
	}
	sub += (*stk)->n;
	_pop(stk, x);

	(*stk)->n -= sub;
}
