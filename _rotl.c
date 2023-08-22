#include "monty.h"
/**
  *_rotl - Operation that rotates the stack to the top
  *@head: stack head
  *@number: line number
  *Return: nothing
 */
void _rotl(stack_t **head,  __attribute__((unused)) unsigned int number)
{
	stack_t *tmp = *head, *aux;

	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}
	aux = (*head)->next;
	aux->prev = NULL;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	tmp->next = *head;
	(*head)->next = NULL;
	(*head)->prev = tmp;
	(*head) = aux;
}
