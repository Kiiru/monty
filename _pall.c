#include "monty.h"

/**
 * _pall - Operation to print all values in a stack,
 * starting from the top of the stack
 * @head: top/head of the stack
 * @number: script line number
 * Return: nothing
 */
void _pall(stack_t **head, unsigned int number)
{
	stack_t *top;

	number = number;
	top = *head;
	if (top == NULL)
		return;
	while (top)
	{
		printf("%d\n", top->n);
		top = top->next;
	}
}
