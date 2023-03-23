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
	if (*stk == NULL)
	{
		dprintf(STDERR_FILENO, "L%u: can't pop an empty stack\n", x);
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

/**
 * _swap - func that swaps the top two elements of the stack.
 * @stk: ptr to ptr to stack
 * @x: line in the file
 */
void _swap(stack_t **stk, unsigned int x)
{
	stack_t *sp = *stk;

	if (glo.lens < 2)
	{
		dprintf(STDERR_FILENO, "L%u: can't swap, stack too short\n", x);
		exit(EXIT_FAILURE);
	}
	if (glo.lens == 2)
	{
		*stk = (*stk)->next;
		return;
	}
	sp = (*stk)->next;
	sp->prev = (*stk)->prev;
	(*stk)->prev->next = sp;
	(*stk)->prev = sp;
	(*stk)->next = sp->next;
	sp->next->prev = *stk;
	sp->next = *stk;
	*stk = sp;
}
