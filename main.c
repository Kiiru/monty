#include "monty.h"


global_t globals = { NULL, NULL, NULL };

/**
 * main - monty code interpreter entry
 * @argc: number of arguments
 * @argv: args array
 * Return: 0 on success, 1 or exit on fail
 */
int main(int argc, char *argv[])
{
	ssize_t readLine;
	unsigned int lineNo;
	size_t size;
	FILE *script;
	char *command;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	script = fopen(argv[1], "r");
	if (!script)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	readLine = 1;
	size = 60;
	globals.script = script;
	lineNo = 0;
	while (readLine > 0)
	{
		command = NULL;
		readLine = getline(&command, &size, script);
		globals.command = command;
		lineNo++;
		if (readLine > 0)
		{
			run(command, &stack, lineNo, script);
		}
		free(command);
	}
	fclose(script);
	return (EXIT_SUCCESS);
}
