#include "monty.h"


void monty_add(stack_t **stack, unsigned int line_number);
void monty_sub(stack_t **stack, unsigned int line_number);
void monty_div(stack_t **stack, unsigned int line_number);
void monty_mul(stack_t **stack, unsigned int line_number);
void monty_mod(stack_t **stack, unsigned int line_number);


/**
 * monty_add - adds the top two items in a linked stack of type stack_t.
 * @stack: a pointer to a stack_t linked list's top mode node.
 * @line_number: The number of a Monty bytecodes file's active line.
 *
 * Description: The top value is dropped and the result is
 *  put in the second value node down.
 */
void monty_add(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_tok_error(short_stack_error(line_number, "add"));
		return;
	}


	(*stack)->next->next->n += (*stack)->next->n;
	monty_pop(stack, line_number);
}


/**
 * monty_sub - a stack_t linked list's second value is
 * subtracted from its top value.
 * @stack: a pointer to a stack_t linked list's top mode node.
 * @line_number: The number of a Monty bytecodes file's active line.
 *
 * Description: The top value is dropped and the result is
 * put in the second value node down.
 */
void monty_sub(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_tok_error(short_stack_error(line_number, "sub"));
		return;
	}


	(*stack)->next->next->n -= (*stack)->next->n;
	monty_pop(stack, line_number);
}


/**
 * monty_div - divides the top value by the second value at the
 * top of a stack_t linked list.
 * @stack: a pointer to a stack_t linked list's top mode node.
 * @line_number: The number of a Monty bytecodes file's active line.
 *
 * Description: The top value is dropped and the result is
 * put in the second value node down.
 */
void monty_div(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_tok_error(short_stack_error(line_number, "div"));
		return;
	}


	if ((*stack)->next->n == 0)
	{
		set_op_tok_error(div_error(line_number));
		return;
	}


	(*stack)->next->next->n /= (*stack)->next->n;
	monty_pop(stack, line_number);
}


/**
 * monty_mul - multiplying the top value by the second value
 * from the top of a stack_t linked list.
 * @stack: a pointer to a stack_t linked list's top mode node.
 * @line_number: The number of a Monty bytecodes file's active line.
 *
 * Description: The top value is dropped and the result is
 * put in the second value node down.
 */
void monty_mul(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_tok_error(short_stack_error(line_number, "mul"));
		return;
	}


	(*stack)->next->next->n *= (*stack)->next->n;
	monty_pop(stack, line_number);
}


/**
 * monty_mod - the top value of a stack_t linked list is used to
 * calculate the modulus of the second value from the top.
 * @stack: a pointer to a stack_t linked list's top mode node.
 * @line_number: The number of a Monty bytecodes file's active line.
 *
 * Description: The top value is dropped and the result is
 * put in the second value node down.
 */
void monty_mod(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_tok_error(short_stack_error(line_number, "mod"));
		return;
	}


	if ((*stack)->next->n == 0)
	{
		set_op_tok_error(div_error(line_number));
		return;
	}


	(*stack)->next->next->n %= (*stack)->next->n;
	monty_pop(stack, line_number);
}

