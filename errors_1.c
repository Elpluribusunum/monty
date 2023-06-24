#include "monty.h"


int usage_error(void);
int malloc_error(void);
int f_open_error(char *filename);
int unknown_op_error(char *opcode, unsigned int line_number);
int no_int_error(unsigned int line_number);


/**
 * usage_error - serious usage errors are printed.
 *
 * Return: (EXIT_FAILURE) is a given
 */
int usage_error(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	return (EXIT_FAILURE);
}


/**
 * malloc_error - serious usage errors are printed.
 *
 * Return: (EXIT_FAILURE) is a given
 */
int malloc_error(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	return (EXIT_FAILURE);
}


/**
 * f_open_error - Contains file name and prints file opening error messages.
 * @filename: Name of file could not be opened.
 *
 * Return: (EXIT_FAILURE) is a given
 */
int f_open_error(char *filename)
{
	fprintf(stderr, "Error: Can't open file %s\n", filename);
	return (EXIT_FAILURE);
}


/**
 * unknown_op_error - Messages of unknown instruction errors are printed.
 * @opcode: Opcode where the error was.
 * @line_number: The line in the Monty bytecode file where the mistake happened
 *
 * Return: (EXIT_FAILURE) is a given
 */
int unknown_op_error(char *opcode, unsigned int line_number)
{
	fprintf(stderr, "L%u: unknown instruction %s\n",
		line_number, opcode);
	return (EXIT_FAILURE);
}


/**
 * no_int_error - error messages for invalid monty_push arguments are printed
 * @line_number: The line in the Monty bytecode file where the mistake happened
 *
 * Return: (EXIT_FAILURE) is a given
 */
int no_int_error(unsigned int line_number)
{
	fprintf(stderr, "L%u: usage: push integer\n", line_number);
	return (EXIT_FAILURE);
}

