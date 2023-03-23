#include "monty.h"

/**
 * _pop - func that removes the top element of the stack
 * @stk: ptr to ptr to stack
 * @x: line in the file
 */
void _pop(stack_t **stk, unsigned int x)
{
	stack_t *del;
	
	del = *stk;
	if (glo.lens == 0)
	{
		dprintf(STDERR_FILENO, "L%u: can't pop an empty stack", x);
		exit(EXIT_FAILURE);
	}
	(*stk)->next->prev = (*stk)->prev;
	(*stk)->prev->next = (*stk)->next;

	if (glo.lens != 1)
		*stk = (*stk)->next;
	else
		*stk = NULL;
	free(del);
	glo.lens--;	
}
