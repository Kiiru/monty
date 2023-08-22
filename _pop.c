#include "monty.h"
/**
 * _pop - Operation that prints the top
 * @head: stack head
 * @number: line number
 * Return: nothing
*/
void _pop(stack_t **head, unsigned int number)
{
	stack_t *h;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", number);
		fclose(globals.script);
		free(globals.command);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	*head = h->next;
	free(h);
}
