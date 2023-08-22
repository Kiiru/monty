#include "monty.h"
/**
 * _pchar - Operation that prints the char at the top of the stack,
 * followed by a new line
 * @head: stack head
 * @number: line number
 * Return: nothing
*/
void _pchar(stack_t **head, unsigned int number)
{
	stack_t *h;

	h = *head;
	if (!h)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", number);
		fclose(globals.script);
		free(globals.command);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	if (h->n > 127 || h->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", number);
		fclose(globals.script);
		free(globals.command);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", h->n);
}
