#ifndef _monty_h_
#define _monty_h_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)

/**
* struct vari_s - struct to contain the global variables
* @lens: length of stack
*/
typedef struct vari_s
{
	size_t lens;
} vari_t;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern vari_t glo;

/* doubly linked list to add elements to the stack*/
stack_t *addto_stack(stack_t **h, const int x);

/*checks the opcode arg and calls a func ptr to the valid opcode*/
void chk_func(char *opr, stack_t **head, unsigned int n);

/* opcode functions*/
void pall(stack_t **stk, unsigned int x);
void push(stack_t **stk, unsigned int x);

/* frees the line in file, frees stack, and closes the file*/
void free_line(int stat, void *av);
void free_list(int stat, void *av);
void closing(int stat, void *av);

#endif
