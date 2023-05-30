#include "monty.h"
/**
 * _pstr - Operation that prints the string starting at the top of the stack,
 * followed by a new
 * @head: stack head
 * @number: line number
 * Return: nothing
*/
void _pstr(stack_t **head, unsigned int number)
{
	stack_t *h;
	(void)number;

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
