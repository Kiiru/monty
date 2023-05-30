#include "monty.h"

/**
 * free_stack - Operation to free a stack
 * @head: head of doubly linked list
 * Return: nothing
 */
void free_stack(stack_t *head)
{
	stack_t *copy;

	copy = head;
	while (head != NULL)
	{
		copy = head->next;
		free(head);
		head = copy;
	}
}

