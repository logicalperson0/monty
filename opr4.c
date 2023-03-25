#include "monty.h"

/**
 * _pchar - prints the char at the top of the stack
 * @chari: ptr to ptr to stack
 * @l: line in the file
 */
void _pchar(stack_t **chari, unsigned int l)
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

/**
 * _pstr - prints the string starting at the top of the stack
 * @stri: ptr to ptr to stack
 * @l: line in the file
 */
void _pstr(stack_t **stri, unsigned int l)
{
	int i;
	stack_t *tra;

	UNUSED(l);

	if (*stri == NULL)
		putchar('\n');
	else
	{
		tra = *stri;

		while (tra != NULL)
		{
			i = tra->n;
			if (i == 0 || (!isascii(i)))
				break;
			putchar(i);
			tra = tra->next;
			if (tra == *stri)
				break;
		}
		putchar('\n');
	}
}

/**
 * r_rotl - rotates the stack to the top.
 * top element of the stack becomes the last one
 * @stk: prt to ptr to stack
 * @l: line in the file
 */
void r_rotl(stack_t **stk, unsigned int l)
{
	stack_t *sec;

	UNUSED(l);

	if (*stk)
	{
		sec = (*stk)->next;

		*stk = sec;
	}
}

/**
 * r_rotr - rotates the stack to the bottom.
 * @stk: prt to ptr to stack
 * @l: line in the file
 */
void r_rotr(stack_t **stk, unsigned int l)
{
	stack_t *rot = *stk;

	UNUSED(l);

	if (*stk)
		*stk = rot->prev;
}
