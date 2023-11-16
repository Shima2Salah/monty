#include "monty.h"
/**
 * add - sum two elemnts at stack top
 * @stack: pointer to stack
 * @line_number: line_number in code
 */
void add(stack_t **stack, unsigned int line_number)
{
if (*stack == NULL || (*stack)->next == NULL)
lineerr(5, line_number);
(*stack)->next->n += (*stack)->n;
pop(stack, line_number);
}
/**
 * sub - subtract two elemnts at stack top
 * @stack: pointer to stack
 * @line_number: line_number in code
 */
void sub(stack_t **stack, unsigned int line_number)
{
if (*stack == NULL || (*stack)->next == NULL)
lineerr(6, line_number);
(*stack)->next->n -= (*stack)->n;
pop(stack, line_number);
}
/**
 * divided - divide two elemnts at stack top
 * @stack: pointer to stack
 * @line_number: line_number in code
 */
void divided(stack_t **stack, unsigned int line_number)
{
if (*stack == NULL || (*stack)->next == NULL)
lineerr(7, line_number);
if ((*stack)->n == 0)
lineerr(8, line_number);
(*stack)->next->n /= (*stack)->n;
pop(stack, line_number);
}
/**
 * mul - multibly two elemnts at stack top
 * @stack: pointer to stack
 * @line_number: line_number in code
 */
void mul(stack_t **stack, unsigned int line_number)
{
if (*stack == NULL || (*stack)->next == NULL)
lineerr(9, line_number);
(*stack)->next->n *= (*stack)->n;
pop(stack, line_number);
}
/**
 * mod - modulus two elemnts at stack top
 * @stack: pointer to stack
 * @line_number: line_number in code
 */
void mod(stack_t **stack, unsigned int line_number)
{
if (*stack == NULL || (*stack)->next == NULL)
lineerr(10, line_number);
if ((*stack)->n == 0)
lineerr(11, line_number);
(*stack)->next->n %= (*stack)->n;
pop(stack, line_number);
}

