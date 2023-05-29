#include "monty.h"

/**
 * main - monty code interpreter entry
 * @argc: number of arguments
 * @argv: args array
 * Return: 0 on success, 1 or exit on fail
 */
int main(int argc, char *argv[])
{
	/* check the arg count, exit on error*/
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
}
