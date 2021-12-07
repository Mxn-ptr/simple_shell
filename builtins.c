#include "main.h"
#include "printf.h"

char *builtin_cmd[] = {
  "cd",
  "exit",
  "env"
};

int (*builtin_function[]) (char **) = {
  &cd_bn,
  &exit_bn,
  &env_bn,
};

int num_built() {
  return sizeof(builtin_cmd) / sizeof(char *);
}

int exit_bn()
{
	return (0);
}

int cd_bn(char **args)
{
	if (args[1] ==  NULL)
	{
		chdir(_getenv("HOME"));
		return (1);
	}
	else
	{
		if (chdir(args[1]) == -1)
		{
			_printf("%s: %s: No such file or directory\n", args[0], args[1]);
			return (-1);
		}
	}
	return (0);
}

int env_bn()
{
	int i;

	for (i = 0; environ[i]; i++)
	{
		_printf("%s\n", environ[i]);
	}
	return (1);
}
int exec_built(char **args)
{
  int i;

  if (args[0] == NULL) {
    return 1;
  }

  for (i = 0; i < num_built(); i++) {
    if (_strcmp(args[0], builtin_cmd[i]) == 0) {
      return (*builtin_function[i])(args);
    }
  }

  return exec(args);
}