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

/**
 * div_ - func that divides the second top element of the stack
 * by the top element of the stack.
 * @stk: ptr to ptr to stack
 * @x: line in the file
 */
void div_(stack_t **stk, unsigned int x)
{
	int div = 0;

	if (glo.lens < 2)
	{
		dprintf(STDERR_FILENO, "L%u: can't div, stack too short\n", x);
		exit(EXIT_FAILURE);
	}
	if ((*stk)->n == 0)
	{
		dprintf(STDERR_FILENO, "L%u: division by zero\n", x);
		exit(EXIT_FAILURE);
	}
	div += (*stk)->n;
	_pop(stk, x);

	(*stk)->n /= div;
}

/**
 * multi - func that multiplies the second top element of the stack
 * with the top element of the stack
 * @stk: ptr to ptr to stack
 * @x: line in the file
 */
void multi(stack_t **stk, unsigned int x)
{
	int mulx = 0;

	if (glo.lens < 2)
	{
		dprintf(STDERR_FILENO, "L%u: can't mul, stack too short\n", x);
		exit(EXIT_FAILURE);
	}
	mulx += (*stk)->n;
	_pop(stk, x);

	(*stk)->n *= mulx;
}
