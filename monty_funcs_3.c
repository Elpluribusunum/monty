#include "monty.h"


void monty_nop(stack_t **stack, unsigned int line_number);
void monty_pchar(stack_t **stack, unsigned int line_number);
void monty_pstr(stack_t **stack, unsigned int line_number);


/**
 * monty_nop - does nothing at all for the Monty opcode "nop".
 * @stack: a pointer to a stack_t linked list's top mode node.
 * @line_number: The Monty bytecodes file's active line number.
 */
void monty_nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}


/**
 * monty_pchar - prints the character located in the stack_t
 * linked list's top value node.
 * @stack: a pointer to a stack_t linked list's top mode node.
 * @line_number: The Monty bytecodes file's active line number
 */
void monty_pchar(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL)
	{
		set_op_tok_error(pchar_error(line_number, "stack empty"));
		return;
	}
	if ((*stack)->next->n < 0 || (*stack)->next->n > 127)
	{
		set_op_tok_error(pchar_error(line_number,
			"value out of range"));
		return;
	}


	printf("%c\n", (*stack)->next->n);
}


/**
 * monty_pstr - prints a stack_t linked list's string content.
 * @stack: a pointer to a stack_t linked list's top mode node.
 * @line_number: The Monty bytecodes file's active line number
 */
void monty_pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = (*stack)->next;


	while (tmp && tmp->n != 0 && (tmp->n > 0 && tmp->n <= 127))
	{
		printf("%c", tmp->n);
		tmp = tmp->next;
	}


	printf("\n");


	(void)line_number;
}

