#include "monty.h"
/**
 * pchar - print char at stack top
 * @stack: pointer to stack
 * @line_number: line_number in code
 */
void pchar(stack_t **stack, unsigned int line_number)
{
if (*stack == NULL)
lineerr(12, line_number);
if ((*stack)->n < 0 || (*stack)->n > 127)
lineerr(13, line_number);
printf("%c\n", (*stack)->n);
}
/**
 * pstr - print string at stack top
 * @stack: pointer to stack
 * @line_number: line_number in code
 */
void pstr(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
stack_t *current = *stack;
while (current != NULL && current->n != 0 &&
current->n >= 0 && current->n <= 127)
{
printf("%c", current->n);
current = current->next;
}
printf("\n");
}
/**
 * rotl - rotates the stack to the top
 * @stack: pointer to stack
 * @line_number: line_number in code
 */
void rotl(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
stack_t *ends;
if (*stack == NULL || (*stack)->next == NULL)
return;
ends = *stack;
while (ends->next != NULL)
ends = ends->next;
ends->next = *stack;
(*stack)->prev = ends;
*stack = (*stack)->next;
(*stack)->prev = NULL;
ends->next->next = NULL;
}
/**
 * rotr - rotates the stack to the bottom
 * @stack: pointer to stack
 * @line_number: line_number in code
 */
void rotr(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
stack_t *ends;
if (*stack == NULL || (*stack)->next == NULL)
return;
ends = *stack;
while (ends->next != NULL)
ends = ends->next;
ends->next = *stack;
(*stack)->prev = ends;
*stack = ends;
ends->prev->next = NULL;
ends->prev = NULL;
}

