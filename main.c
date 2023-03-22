#include "monty.h"

/**
 * main - Monty bytecode interpreter
 * @ac: num of args passed
 * @av: array of args
 *
 * Return: EXIT_SUCCESS OR EXIT_FAILURE
 */
int main(int ac, char *av[])
{
	FILE *fd = NULL;
	size_t buff = 0;
	ssize_t nlin = 0;
	char *line = NULL, *opr = NULL;
	unsigned int num = 0;
	stack_t *list = NULL;

	lens = 0;

	if (ac != 2)
	{
		dprintf(STDERR_FILENO, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fd = fopen(av[1], "r");
	if (fd == NULL)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	on_exit(free_line, &line);
	on_exit(free_list, &list);
	on_exit(closing, fd);

	nlin = getline(&line, &buff, fd);
	while (nlin != -1)
	{
		num++;
		opr = strtok(line, "\n\t\r ");
		if (opr != NULL && opr[0] != '#')
			chk_func(opr, &list, num);
	}
	exit(EXIT_SUCCESS);
}
