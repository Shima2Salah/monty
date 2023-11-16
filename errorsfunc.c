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
 * pusherr - functn to print errors
 * @line_num: line_number in code
 */
void pusherr(unsigned int line_num)
{
fprintf(stderr, "L%u: usage: push integer\n", line_num);
exit(EXIT_FAILURE);
}

