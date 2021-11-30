#include "main.h"

char **split(char *line, char *limit)
{
	int bufsize = 64, idx = 0;
	char **tokens = NULL;
	char *token, **tokens_back;

	tokens = malloc(sizeof(char *) * bufsize);
	if (tokens == NULL)
	{
		perror("Malloc tokens fails");
		exit(EXIT_FAILURE);
	}

	token = strtok(line, limit);
	while (token)
	{
		tokens[idx] = token;
		idx++;

		if (idx >= bufsize)
		{
			bufsize += 64;
			tokens_back = tokens;
			tokens = realloc(tokens, bufsize * sizeof(char *));
			if (tokens == NULL)
			{
				free(tokens_back);
				perror("Realloc tokens fails");
				exit(EXIT_FAILURE);
			}
		}
		token = strtok(NULL, limit);
	}
	tokens[idx] = NULL;
	return tokens;
}
	
