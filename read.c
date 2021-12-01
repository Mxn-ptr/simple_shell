#include "main.h"

/**
 * readline - read the input of the user
 * Return: the input
 */

char *readline(void)
{
	char *input = NULL;
	size_t bufsize = 0;

	if (getline(&input, &bufsize, stdin) != -1)
		;
	else
	{
		perror("Read fails");
		exit(EXIT_FAILURE);
	}

	return (input);
}
