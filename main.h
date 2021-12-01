#ifndef MAIN_H
#define MAIN_H

#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stddef.h>

void loop(void);
char *readline(void);
char **split(char *line, char *limit);
int exec(char **args);

#endif
