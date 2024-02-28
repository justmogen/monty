#include "monty.h"

/**
 * _sub - subtracts the top element of the stack from the second top element
 * @stack: pointer to the top of the stack
 * @line_number: line number of opcode occurs on
*/
void _sub(stack_t **stack, unsigned int line_number)
{
    stack_t *temp = *stack;
    int sub = 0, i = 0;

    if (temp == NULL)
    {
        fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    while (temp)
    {
        temp = temp->next;
        i++;
    }

    if (stack == NULL || (*stack)->next == NULL || i < 2)
    {
        fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }
    sub = (*stack)->next->n - (*stack)->n;
    _pop(stack, line_number);
    (*stack)->n = sub;
}

/**
 * _div - divides the second top element of the stack by the top element
 * @stack: pointer to the top of the stack
 * @line_number: line number of opcode occurs on
*/
void _div(stack_t **stack, unsigned int line_number)
{
    int div = 0;

    if (*stack == NULL || (*stack)->next == NULL)
    {
        fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
        free(var_global.buffer);
        fclose(var_global.file);
        free_dlistint(*stack);
        exit(EXIT_FAILURE);
    }

    else if ((*stack)->n == 0)
    {
        fprintf(stderr, "L%d: division by zero\n", line_number);
        free(var_global.buffer);
        fclose(var_global.file);
        free_dlistint(*stack);
        exit(EXIT_FAILURE);
    }
    else
    {
        div = (*stack)->n;
        _pop(stack, line_number);
        (*stack)->n /= div;
        ;
    }
}

/**
 * _mul - multiplies the second top element of the stack with the top element
 * @stack: pointer to the top of the stack
 * @line_number: line number of opcode occurs on
*/

void _mul(stack_t **stack, unsigned int line_number)
{
    int mul = 0;

    if (*stack == NULL || (*stack)->next == NULL)
    {
        fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
        free(var_global.buffer);
        fclose(var_global.file);
        free_dlistint(*stack);
        exit(EXIT_FAILURE);
    }
    else
    {
        mul = (*stack)->n;
        _pop(stack, line_number);
        (*stack)->n *= mul;
    }
}

/**
 * _mod - computes the rest of the division of the second top element of the stack by the top element
 * @stack: pointer to the top of the stack
 * @line_number: line number of opcode occurs on
*/

void _mod(stack_t **stack, unsigned int line_number)
{
    int mod = 0;

    if (*stack == NULL || (*stack)->next == NULL)
    {
        fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
        free(var_global.buffer);
        fclose(var_global.file);
        free_dlistint(*stack);
        exit(EXIT_FAILURE);
    }
    else if ((*stack)->n == 0)
    {
        fprintf(stderr, "L%d: division by zero\n", line_number);
        free(var_global.buffer);
        fclose(var_global.file);
        free_dlistint(*stack);
        exit(EXIT_FAILURE);
    }
    else
    {
        mod = (*stack)->n;
        _pop(stack, line_number);
        (*stack)->n %= mod;
    }
}