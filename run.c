#include "monty.h"

/**
 * run - Operation to run a command from a script
 * @command: command args
 * @stack: head of a linked list
 * @script: pointer to a monty script
 * @counter: line count
 * Return: 0 on success, 1 on fail
 */
int run(char *command, stack_t **stack, unsigned int counter, FILE *script)
{
	unsigned int i;
	char *op;

	instruction_t ops[] = {
		{"push", _push}, {"pall", _pall}, {"pint", _pint},
		{"pop", _pop}, {"swap", _swap}, {"add", _add},
		{"nop", _nop}, {"sub", _sub}, {"div", _div},
		{"mul", _mul}, {"mod", _mod}, {"pchar", _pchar},
		{"pstr", _pstr}, {"rotl", _rotl},
		{NULL, NULL}
	};

	/* Tokenize the command string to handle space*/
	op = strtok(command, " \n\t");
	/*Check for comments in the script*/
	if (op && op[0] == '#')
		return (0);
	
	i = 0;
	globals.args = strtok(NULL, " \n\t");
	while (ops[i].opcode && op)
	{
		if (strcmp(op, ops[i].opcode) == 0)
		{
			ops[i].f(stack, counter);
			return (0);
		}
		i++;
	}
	if (op && ops[i].opcode == NULL)
	{
		/*hundle unknown instruction*/
		fprintf(stderr, "L%d: unknown instruction %s\n", counter, op);
		fclose(script);
		free(command);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	return (1);
}
