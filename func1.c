#include "monty.h"
/**
 * pint - print val at stack top
 * @stack: pointer to stack
 * @line_number: line_number in code
 */
void pint(stack_t **stack, unsigned int line_number)
{
if (*stack == NULL)
lineerr(2, line_number);
printf("%d\n", (*stack)->n);
}
/**
 * pop - remove val at stack top
 * @stack: pointer to stack
 * @line_number: line_number in code
 */
void pop(stack_t **stack, unsigned int line_number)
{
stack_t *temp;
if (*stack == NULL)
lineerr(3, line_number);
temp = *stack;
*stack = (*stack)->next;
if (*stack != NULL)
(*stack)->prev = NULL;
free(temp);
}
/**
 * swap - swap two elemnts at stack top
 * @stack: pointer to stack
 * @line_number: line_number in code
 */
void swap(stack_t **stack, unsigned int line_number)
{
int temp;
if (*stack == NULL || (*stack)->next == NULL)
lineerr(4, line_number);
temp = (*stack)->n;
(*stack)->n = (*stack)->next->n;
(*stack)->next->n = temp;
}
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
 * nop - func not do any thing
 * @stack: pointer to stack
 * @line_number: line_number in code
 */
void nop(stack_t **stack, unsigned int line_number)
{
(void)stack;
(void)line_number;
}



