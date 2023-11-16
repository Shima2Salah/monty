#include "monty.h"
/**
 * myerror - functn to print errors
 * @err: integer represent error
 */
void myerror(int err)
{
if (err == 1)
fprintf(stderr, "Error: malloc failed\n");
else if (err == 2)
fprintf(stderr, "USAGE: monty file\n");
exit(EXIT_FAILURE);
}
/**
 * nofilerr - functn to print errors
 * @argv: input argument
 */
void nofilerr(char *argv)
{
fprintf(stderr, "Error: Can't open file %s\n", argv);
exit(EXIT_FAILURE);
}
/**
 * instructerr - functn to print errors
 * @line_num: line_number in code
 * @monstr: opcode input
 */
void instructerr(unsigned int line_num, char *monstr)
{
fprintf(stderr, "L%u: unknown instruction %s\n", line_num, monstr);
exit(EXIT_FAILURE);
}
/**
 * lineerr - functn to print errors
 * @err: integer represent error
 * @line_num: line_number in code
 */
void lineerr(int err, unsigned int line_num)
{
if (err == 1)
fprintf(stderr, "L%u: usage: push integer\n", line_num);
else if (err == 2)
fprintf(stderr, "L%u: can't pint, stack empty\n", line_num);
else if (err == 3)
fprintf(stderr, "L%u: can't pop an empty stack\n", line_num);
else if (err == 4)
fprintf(stderr, "L%u: can't swap, stack too short\n", line_num);
else if (err == 5)
fprintf(stderr, "L%u: can't add, stack too short\n", line_num);
else if (err == 6)
fprintf(stderr, "L%u: can't sub, stack too short\n", line_num);
else if (err == 7)
fprintf(stderr, "L%u: can't div, stack too short\n", line_num);
else if (err == 8)
fprintf(stderr, "L%u: division by zero\n", line_num);
else if (err == 9)
fprintf(stderr, "L%u: can't mul, stack too short\n", line_num);
else if (err == 10)
fprintf(stderr, "L%u: can't mod, stack too short\n", line_num);
else if (err == 11)
fprintf(stderr, "L%u: division by zero\n", line_num);
exit(EXIT_FAILURE);
}

