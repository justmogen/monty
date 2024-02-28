#include "monty.h"

/**
 * _pstr - prints ASCII value of elements in stack until it encounters 0
 * @stack: pointer to the top of the stack
 * @line_number: line number of opcode occurs on
*/

void _pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	int asc;

	(void)line_number;

	while (temp)
	{
		asc = temp->n;
		if (asc == 0 || _isalpha(asc) == 0)
			break;
		putchar(asc);
		temp = temp->next;
	}
	putchar('\n');
}

/**
 * _rotl - rotates the stack to the top
 * @stack: pointer to the top of the stack
 * @line_number: line number of opcode occurs on
*/

void _rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	int first;

	if (!line_number || !stack || !*stack || !(*stack)->next)
		return;

	first = temp->n;

	while (temp->next)
	{
		/**
		 * 1. Set the current node's value to the next node's value
		 * 2. Move to the next node
		 * Another way :
		 * temp = temp->next;
		 * temp->prev->n = temp->n;
		*/
		temp->n = temp->next->n;
		temp = temp->next;
	}

	temp->n = first;
}

/**
 * _rotr - rotates the stack to the bottom
 * @stack: pointer to the top of the stack
 * @line_number: line number of opcode occurs on
*/

void _rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	int last;

	if (!line_number || !stack || !*stack || !(*stack)->next)
		return;

	while (temp->next)
		temp = temp->next;

	last = temp->n;

	while (temp->prev)
	{
		temp->n = temp->prev->n;
		temp = temp->prev;
	}
	temp->n = last;
}
