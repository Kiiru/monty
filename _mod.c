#include "monty.h"
/**
 * _mod - Operation that computes the rest of the division of the second
 * top element of the stack by the top element of the stack
 * @head: stack head
 * @number: line number
 * Return: nothing
*/
void _mod(stack_t **head, unsigned int number)
{
	stack_t *h;
	int len = 0, aux;

	h = *head;
	while (h)
	{
		h = h->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", number);
		fclose(globals.script);
		free(globals.command);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	if (h->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", number);
		fclose(globals.script);
		free(globals.command);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	aux = h->next->n % h->n;
	h->next->n = aux;
	*head = h->next;
	free(h);
}
