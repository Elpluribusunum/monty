#include "monty.h"
/**
* free_stack - unlinks a double-linked list
* @head: front of the line
*/
void free_stack(stack_t *head)
{
	stack_t *aux;

	aux = head;
	while (head)
	{
		aux = head->next;
		free(head);
		head = aux;
	}
}
