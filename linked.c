#include "monty.h"

/**
 * addto_stack - add new element to a double linked list circular
 * @h: ptr to list
 * @x: parameter int
 *
 * Return: ptr to a new element for the stack
 */
stack_t *addto_stack(stack_t **h, const int x)
{
	stack_t *add;

	if (h == NULL)
		return (NULL);

	add = malloc(sizeof(stack_t));
	if (add == NULL)
		return (NULL);
	add->n = x;

	if (*h == NULL)
	{
		add->prev = add;
		add->next = add;
	}
	else
	{
		(*h)->prev->next = add;
		add->prev = (*h)->prev;
		(*h)->prev = add;
		add->next = *h;
	}
	if (lens == 0)
		*h = add;
	return (add);
}
