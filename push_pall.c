#include "monty.h"
/**
 * push - functn to add node
 * @stack: pointer to stack
 * @line_number: line_number in code
 */
void push(stack_t **stack, unsigned int line_number)
{
stack_t *nod;
if (glob.arg == NULL || !isdigit(*glob.arg))
lineerr(1, line_number);
nod = malloc(sizeof(stack_t));
if (nod == NULL)
myerror(1);
nod->n = atoi(glob.arg);
nod->prev = NULL;
nod->next = NULL;
if (glob.struc_type == 1)
{
nod->next = *stack;
if (*stack != NULL)
(*stack)->prev = nod;
*stack = nod;
}
else if (glob.struc_type == 0)
{
if (*stack == NULL)
{
*stack = nod;
}
else
{
stack_t *current = *stack;
while (current->next != NULL)
current = current->next;
current->next = nod;
nod->prev = current;
}
}
}
/**
 * pall - functn to print node
 * @stack: pointer to stack
 * @line_number: line_number in code
 */
void pall(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
stack_t *current;
if (glob.struc_type == 1)
{
current = *stack;
while (current != NULL)
{
printf("%d\n", current->n);
current = current->next;
}
}
else if (glob.struc_type == 0)
{
current = *stack;
if (current != NULL)
{
while (current->next != NULL)
current = current->next;
while (current != NULL)
{
printf("%d\n", current->n);
current = current->prev;
}
}
}
}

