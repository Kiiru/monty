#include "monty.h"

/**
 * _pint - Operation to print the top
 * @head: stack head
 * @counter: line number
 * Return: nothing
*/
void _pint(stack_t **head, unsigned int counter)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", counter);
		fclose(globals.script);
		free(globals.command);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}
