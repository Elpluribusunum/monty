#include "monty.h"
/**
 * f_pstr - prints a new line after the string at the
 * top of the stack
 * @head: pile head
 * @counter: line_number
 * Return: the end
*/
void f_pstr(stack_t **head, unsigned int counter)
{
	stack_t *h;
	(void)counter;

	h = *head;
	while (h)
	{
		if (h->n > 127 || h->n <= 0)
		{
			break;
		}
		printf("%c", h->n);
		h = h->next;
	}
	printf("\n");
}
