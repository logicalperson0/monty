#include "monty.h"
/**
 * stk_s - sets to stack (LIFO)
 * @h: ptr to ptr to head
 * @l: line num of opr
 */
void stk_s(stack_t **h, unsigned int l)
{
	UNUSED(h);
	UNUSED(l);
	glo.qu = STA;
}

/**
 * ques - sets to queue (FIFO)
 * @h: ptr to ptr to head
 * @l: line num of opr
 */
void ques(stack_t **h, unsigned int l)
{
	UNUSED(h);
	UNUSED(l);
	glo.qu = QUE;
}
