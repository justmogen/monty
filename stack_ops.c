#include "monty.h"
/**
* _push - adds int to the top of the stack
* @stack: pointer to the top of the stack
* @line_number: line number of opcode occurs on
*/
void _push(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	stack_t *top = malloc(sizeof(stack_t));
	(void)line_number;

	if (top == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	top->n = var_global.push_arg;
	top->prev = NULL;
	top->next = *stack;
	if (*stack != NULL)
		(*stack)->prev = top;
	*stack = top;
}

/**
* _pall - prints all the values on the stack, starting from top
* @stack: pointer to the top of the stack
* @line_number: line number of opcode occurs on
*/

void _pall(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	stack_t *temp = *stack;

	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

/**
* _pint - prints the value at the top of the stack, followed by a new line
* @stack: pointer to the top of the stack
* @line_number: line number of opcode occurs on
*/

void _pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

/**
* _pop - removes the top element of the stack
* @stack: pointer to the top of the stack
* @line_number: line number of opcode occurs on
*/

void _pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	*stack = temp->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(temp);
}

/**
* free_dlistint - frees a dlistint_t list
* @head: pointer to the top of the stack
*/
void free_dlistint(stack_t *head)
{
	stack_t *temp;

	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}
