#include "monty.h"

/**
 * addnode - add node to the head stack
 * @head: head of the stack
 * @n: new_value
 * Return: no return
*/
void addnode(stack_t **head, int n)
{

	stack_t *new_node, *aux;

	aux = *head;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{ printf("Error\n");
		exit(0); }
	if (aux)
		aux->prev = new_node;
	new_node->n = n;
	new_node->next = *head;
	new_node->prev = NULL;
	*head = new_node;
}

/**
 * _push - Operation to add a node to a stack
 * @head: linked list head
 * @number: line number
 * Return: nothing
 */
void _push(stack_t **head, unsigned int number)
{
	int n, j = 0, flag = 0;

	if (globals.args)
	{
		if (globals.args[0] == '-')
			j++;
		for (; globals.args[j] != '\0'; j++)
		{
			if (globals.args[j] > 57 || globals.args[j] < 48)
				flag = 1;
		}
		if (flag == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", number);
			fclose(globals.script);
			free(globals.command);
			free_stack(*head);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", number);
		fclose(globals.script);
		free(globals.command);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	n = atoi(globals.args);
	addnode(head, n);
}
