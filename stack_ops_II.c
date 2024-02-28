#include "monty.h"

/**
 * _swap - swaps the top two elements of the stack
 * @stack: pointer to the top of the stack
 * @line_number: line number of opcode occurs on
 * Return: void
*/

void _swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
int temp_n;

	if (temp == NULL || temp->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp_n = temp->n;
	temp->n = temp->next->n;
	temp->next->n = temp_n;
}

/**
 * _add - adds the top two elements of the stack
 * @stack: pointer to the top of the stack
 * @line_number: line number of opcode occurs on
 */

void _add(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	int sum = 0, i = 0;

	if (temp == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	while (temp)
	{
		temp = temp->next;
		i++;
	}

	if (stack == NULL || (*stack)->next == NULL || i < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	sum = (*stack)->n + (*stack)->next->n;
	_pop(stack, line_number);
	(*stack)->n = sum;

}

/**
 * _nop - does nothing
 * @stack: pointer to the top of the stack
 * @line_number: line number of opcode occurs on
 * Return: void
 */

void _nop(__attribute__((unused)) stack_t **stack,
__attribute__((unused)) unsigned int line_number)
{
	;
}

/**
 * _pchar - prints the ASCII value of the top element of the stack
 * @stack: pointer to the top of the stack
 * @line_number: line number of opcode occurs on
*/

void _pchar(stack_t **stack, unsigned int line_number)
{
	int n;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		free(var_global.buffer);
		fclose(var_global.file);
		free_dlistint(*stack);
		exit(EXIT_FAILURE);
	}

	n = (*stack)->n;
	if (n < 0 || n > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		free(var_global.buffer);
		fclose(var_global.file);
		free_dlistint(*stack);
		exit(EXIT_FAILURE);
	}

	putchar(n);
	putchar('\n');
}

/**
 * _isalpha - checks if int c is a letter, lowercase or uppercase
 * @c: int to be checked
 * Return: 1 if c is a letter, lowercase or uppercase, 0 otherwise
*/

int _isalpha(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		return (1);
	return (0);
}
