#include "main.h"


/**
 * loop - loop the prompt
 */

void loop(void)
{
	char *read;
	char **args;
	int status;

	do {
		write(STDIN_FILENO, "$ ", 2);
		read = readline();
		args = split(read, " \t\r\n");
		status = exec_built(args);

		free(read);
		free(args);
	} while (status);
}
