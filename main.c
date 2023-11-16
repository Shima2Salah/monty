#include "monty.h"
/**
 * main - the entery point.
 * @argc: argument count
 * @argv: arguments entered
 * Return: 0 success or 1 unsuccess
 */
int main(int argc, char *argv[])
{
FILE *fd;
if (argc != 2)
myerror(2);
fd = fopen(argv[1], "r");
if (fd == NULL)
nofilerr(argv[1]);
input_file(fd);
fclose(fd);
exit(EXIT_SUCCESS);
}
/**
 * input_file - functn to get lines.
 * @fd: file descripitor
 */
void input_file(FILE *fd)
{
char *cmdin = NULL;
size_t cmdinlen = 0;
ssize_t lineinput;
unsigned int line_num = 0;
stack_t *stack = NULL;
glob.nod_num = 1;
while (1)
{
lineinput = getline(&cmdin, &cmdinlen, fd);
if (lineinput == -1)
{
if (feof(fd))
{
free(cmdin);
free_stack(stack);
fclose(fd);
exit(EXIT_SUCCESS);
}
else
{
free(cmdin);
free_stack(stack);
fclose(fd);
exit(EXIT_FAILURE);
}
}
line_num++;
str_token(cmdin, line_num, &stack, fd);
}
}

/**
 * str_token - functn to tokenize opcodes
 * @cmdin: opcode input
 * @line_num: line_number in code
 * @stack: pointer to stack
 * @fd: file descripitor
 */
void str_token(char *cmdin, unsigned int line_num, stack_t **stack, FILE *fd)
{
instruction_t instruct;
instruct.opcode = strtok(cmdin, " \t\n");
if (instruct.opcode == NULL || instruct.opcode[0] == '#')
return;
instruct.f = opcode_exec(instruct.opcode);
if (instruct.f == NULL)
{
instructerr(line_num, instruct.opcode);
free(cmdin);
free_stack(*stack);
fclose(fd);
exit(EXIT_FAILURE);
}
glob.arg = strtok(NULL, " \t\n");
instruct.f(stack, line_num);
}

/**
 * opcode_exec - functn to excute opcodes
 * @opcode: opcode input
 * Return: function or not
 */
void (*opcode_exec(char *opcode))(stack_t **stack, unsigned int line_number)
{
instruction_t instructions[] = {{"push", push}, {"pall", pall}, {"pint", pint},
{"pop", pop}, {"swap", swap}, {"add", add}, {NULL, NULL}};
int i = 0;
while (instructions[i].opcode != NULL)
{
if (strcmp(opcode, instructions[i].opcode) == 0)
return (instructions[i].f);
i++;
}
return (NULL);
}
/**
 * free_stack - functn to free nodes
 * @stack: pointer to stack
 */
void free_stack(stack_t *stack)
{
stack_t *current = stack;
stack_t *after;
while (current != NULL)
{
after = current->next;
free(current);
current = after;
}
}



