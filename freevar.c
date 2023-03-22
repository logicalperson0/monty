#include "monty.h"

/**
 * free_line - frees the lines in file
 * @stat: exit stat
 * @av: ptr to line
 */
void free_line(int stat, void *av)
{
	char **ptr = av;

	UNUSED(stat);

	if (*ptr != NULL)
		free(*ptr);
}

/**
 * free_list - free list(stack) on exit the program
 * @stat: exit stat
 * @av: ptr to line in the file
 */
void free_list(int stat, void *av)
{
	stack_t **h, *del;

	UNUSED(stat);

	h = (stack_t **)av;
	/* to break the circle*/
	if (*h)
	{
		(*h)->prev->next = NULL;
		(*h)->prev = NULL;
	}
	while (*h != NULL)
	{
		del = *h;
		*h = (*h)->next;
		free(del);
	}
	glo.lens = 0;
}

/**
 * closing - closes the file on exit
 * @stat: exit stat
 * @av: ptr to line
 */
void closing(int stat, void *av)
{
	FILE *fd;

	UNUSED(stat);
	fd = (FILE *)av;

	fclose(fd);
}
