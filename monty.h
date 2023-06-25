#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

/* STRUCTURES */
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
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
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct allocation_history - tracks and stores allocations
 * @mem_ptr: pointer to allocated memory
 * @next: pointer to next node in list
 *
 * Description: stores a pointer to each allocation, allowing
 * greater organization and more efficient freeing
 */
typedef struct allocation_history
{
	char *mem_ptr;
	struct allocation_history *next;

} mem_list;

/* PROTOTYPES */
void exec_op(char **args);
void (*get_op(char *func_string))(stack_t **head, unsigned int line_number);
void print_error(size_t, char *);

/* OPCODE PROTOTYPES */
void _push_stack(char **args);
void _push_queue(char **args);
void _pall(stack_t **head, unsigned int line_number);
void _pint(stack_t **head, unsigned int line_number);
void _pop(stack_t **head, unsigned int line_number);
void _add(stack_t **head, unsigned int line_number);
void _swap(stack_t **head, unsigned int line_number);
void _nop(stack_t **head, unsigned int line_number);
void _sub(stack_t **head, unsigned int line_number);
void _div(stack_t **head, unsigned int line_number);
void _mod(stack_t **head, unsigned int line_number);
void _mul(stack_t **head, unsigned int line_number);
void _rotl(stack_t **head, unsigned int line_number);
void _rotr(stack_t **head, unsigned int line_number);
void _pchar(stack_t **head, unsigned int line_number);
void _pstr(stack_t **head, unsigned int line_number);
void _stack(stack_t **head, unsigned int line_number);
void _queue(stack_t **head, unsigned int line_number);

/* UTILITY PROTOTYPES */
size_t node_count(stack_t **h);
void free_memory(const char *scope);
void free_mem_list(mem_list **h);
void free_stack_t(stack_t **h);
void add_mem_list(char *ptr);
void locate_tail(stack_t **tail);

/* EXTERNS */
extern unsigned int line_number; /* input line number */
unsigned int line_number;
extern FILE *input_file; /* input file pointer */
FILE *input_file;
extern stack_t *head; /* stack head */
stack_t *head;
extern stack_t *tail; /* end of list */
stack_t *tail;
extern mem_list *misc_mem_head; /* head of misc mem tracker */
mem_list *misc_mem_head;
extern size_t list_mode; /* tracks whether or not list is stack or queue */
size_t list_mode;

#endif /* MONTY_H */
