#include "main.h"

char *_getenv(char *name)
{
	char *tok;
	int i;

	for (i = 0; environ[i]; i++)
	{
		tok = strtok(environ[i], "=");
		if (_strcmp(tok, name) == 0)
		{
			tok = strtok(NULL, "=");
			return (tok); 
		}
	}
	return (name);
}