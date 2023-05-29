#include "monty.h"

/**
 * main - monty code interpreter entry
 * @argc: number of arguments
 * @argv: args array
 * Return: 0 on success, 1 or exit on fail
 */
int main(int argc, char *argv[])
{
	int readLine, counter;
	size_t size;
	FILE *script;
	char *command;

	/* check the arg count, exit on error*/
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
	size = 0;
	while (readLine > 0)
	{
		command = NULL;
		readLine = getline(&command, &size, script);
		counter++;
		if (readLine > 0)
		{
			// run the command
		}
		free(command);
	}
	fclose(script);
	return (EXIT_SUCCESS);
}
