#include "monty.h"


int short_stack_error(unsigned int line_number, char *op);
int div_error(unsigned int line_number);
int pop_error(unsigned int line_number);
int div_error(unsigned int line_number);
int pchar_error(unsigned int line_number, char *message);


/**
 * pop_error - pop error messages are printed for empty stacks
 * @line_number: script line number where the error was recorded
 *
 * Return: Always use (EXIT_FAILURE).
 */
int pop_error(unsigned int line_number)
{
	fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
	return (EXIT_FAILURE);
}


/**
 * pint_error - pint error messages are printed for empty stacks.
 * @line_number: line no where the problem occurred in the Monty bytecodes file
 *
 * Return: Always use (EXIT_FAILURE)
 */
int pint_error(unsigned int line_number)
{
	fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
	return (EXIT_FAILURE);
}


/**
 * short_stack_error - error messages for the Monty Math function a
 * printed for stacks and queues with less than two nodes.
 * @line_number: line no where the problem occurred in the Monty bytecodes file
 * @op: Operation where the mistake happened
 *
 * Return: Always use (EXIT_FAILURE)
 */
int short_stack_error(unsigned int line_number, char *op)
{
	fprintf(stderr, "L%u: can't %s, stack too short\n", line_number, op);
	return (EXIT_FAILURE);
}


/**
 * div_error - divides by 0 and prints division error messages.
 * @line_number: line no where the problem occurred in the Monty bytecodes file
 *
 * Return: Always use (EXIT_FAILURE)
 */
int div_error(unsigned int line_number)
{
	fprintf(stderr, "L%u: division by zero\n", line_number);
	return (EXIT_FAILURE);
}


/**
 * pchar_error - pchar error messages are printed for non-character
 * values and empty stacks.
 * @line_number: line no where the problem occurred in the Monty bytecodes file
 * @message: To print the relevant error message.
 *
 * Return: Always use (EXIT_FAILURE
 */
int pchar_error(unsigned int line_number, char *message)
{
	fprintf(stderr, "L%u: can't pchar, %s\n", line_number, message);
	return (EXIT_FAILURE);
}

