#ifndef MONTY_H
#define MONTY_H
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/types.h>
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
int n;
struct stack_s *prev;
struct stack_s *next;
} stack_t;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
char *opcode;
void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
/**
 * struct argument - save arguments in node
 * @nod_num: integer
 * @arg: points to aruments to be used in node
 *
 * Description: save arguments in node
 * for stack, queues, LIFO, FIFO
 */
typedef struct argument
{
int nod_num;
char *arg;
} argument_t;
argument_t glob;
extern stack_t *stack;
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void (*opcode_exec(char *opcode))(stack_t **stack, unsigned int line_number);
void free_stack(stack_t *stack);
void input_file(FILE *fd);
void str_token(char *cmdin, unsigned int line_num, stack_t **stack, FILE *fd);
void myerror(int err);
void nofilerr(char *argv);
void pusherr(unsigned int line_num);
void instructerr(unsigned int line_num, char *monstr);
#endif
