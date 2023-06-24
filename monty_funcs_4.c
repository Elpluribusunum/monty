#include "monty.h"


void monty_rotl(stack_t **stack, unsigned int line_number);
void monty_rotr(stack_t **stack, unsigned int line_number);
void monty_stack(stack_t **stack, unsigned int line_number);
void monty_queue(stack_t **stack, unsigned int line_number);


/**
 * monty_rotl - rotates a stack_t linked list's top value to the bottom.
 * @stack: a pointer to a stack_t linked list's top mode node
 * @line_number: The number of a Monty bytecodes file's active line.
 */
void monty_rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *top, *bottom;


	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
		return;


	top = (*stack)->next;
	bottom = (*stack)->next;
	while (bottom->next != NULL)
	bottom = bottom->next;


	top->next->prev = *stack;
	(*stack)->next = top->next;
	bottom->next = top;
	top->next = NULL;
	top->prev = bottom;


	(void)line_number;
}


/**
 * monty_rotr - rotates a stack_t linked list's top value to the bottom.
 * @stack: a pointer to a stack_t linked list's top mode node
 * @line_number: The number of a Monty bytecodes file's active line.
 */
void monty_rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *top, *bottom;


	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
		return;


	top = (*stack)->next;
	bottom = (*stack)->next;
	while (bottom->next != NULL)
	bottom = bottom->next;


	bottom->prev->next = NULL;
	(*stack)->next = bottom;
	bottom->prev = *stack;
	bottom->next = top;
	top->prev = bottom;


	(void)line_number;
}


/**
 * monty_stack - a queue is changed into a stack.
 * @stack: a pointer to a stack_t linked list's top mode node
 * @line_number: The number of a Monty bytecodes file's active line.
 */
void monty_stack(stack_t **stack, unsigned int line_number)
{
	(*stack)->n = STACK;
	(void)line_number;
}


/**
 * monty_queue - a queue is changed into a stack.
 * @stack: a pointer to a stack_t linked list's top mode node
 * @line_number: The number of a Monty bytecodes file's active line.
 */
void monty_queue(stack_t **stack, unsigned int line_number)
{
	(*stack)->n = QUEUE;
	(void)line_number;
}

