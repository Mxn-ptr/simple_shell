#include "main.h"

char *readline(void)
{
	char *input = NULL;
	size_t bufsize = 0;

	if (getline(&input, &bufsize, stdin) != -1)
		;
	else
	{
		perror("Read failure");
		exit(EXIT_FAILURE);
	}
	return (input);
}
