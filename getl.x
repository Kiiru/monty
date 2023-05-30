#include "monty.h"

/**
 */
int getline(char **lineptr, size_t *n, FILE *stream)
{
	char chunk[128];

	if (lineptr == NULL || n == NULL)
		return (-1);

	if (stream == NULL)
		return (-1);

	if (*lineptr == NULL)
	{
		*n = sizeof(chunk);
		if ((*lineptr = malloc(*n)) == NULL)
		{
			return (-1);
		}
	}
	(*lineptr)[0] = '\0';

	while(fgets(chunk, sizeof(chunk), stream) != NULL)
	{
		if(*n - strlen(*lineptr) < sizeof(chunk))
		{
			*n *= 2;
			if ((*lineptr = realloc(lineptr, *n)) == NULL)
			{
				free(lineptr);
				return (-1);
			}
		}

		strcat(*lineptr, chunk);

		if ((*lineptr)[strlen(*lineptr) - 1] == '\n')
		{
			return strlen(*lineptr);
		}
	}
	return (-1);
}
