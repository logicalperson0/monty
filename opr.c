#include "monty.h"
#include <ctype.h>

static int _digit(char *stk);

/**
 * pall - prints all values in stack
 * @stk: ptr to ptr to head
 * @x: line num of opr
 */
void pall(stack_t **stk, unsigned int x)
{
	stack_t *h;

	UNUSED(x);

	h = *stk;

	while (h != NULL)
	{
		printf("%d\n", h->n);
		h = h->next;
		if (h == *stk)
			return;
	}
}

/**
 * push - prints value on top of stack
 * @stk: ptr to ptr to head
 * @x: line num of opr
 */
void push(stack_t **stk, unsigned int x)
{
	char *args;
	int n;

	args = strtok(NULL, "\n\t ");
	if (args == NULL || _digit(args))
	{
		dprintf(STDERR_FILENO, "L%u: usage: push integer\n", x);
		exit(EXIT_FAILURE);
	}
	n = atoi(args);
	if (!addto_stack(stk, n))
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	glo.lens++;
}

/**
 * _digit - chk if digit is an int
 * @stk: ptr to ptr to head
 * Return: 0 for success, 1 otherwise
 */
static int _digit(char *stk)
{
	int c;

	for (c = 0; stk[c]; c++)
	{
		if (stk[c] == '-' && c == 0)
			continue;
		if (isdigit(stk[c]) == 0)
			return (1);
	}
	return (0);
}
