#include "main.h"

/**
 *list_builtins - search for match and execute the associate builtin
 * @info: Pointer to struct containing the program's data
 * Return: Returns the return of the function executed if it matches
 * otherwise it returns -1.
 **/
int list_builtins(data_program *info)
{
	int i;
	builtins options[] = {
		{"exit", exit_func},
		{"help", help_ builtin},
		{"cd", curr_dir_builtin},
		{"alias", alias_builtin},
		{"env", environ_builtin},
		{"setenv", set_environ_builtin},
		{"unsetenv", unset_env_builtin},
		{NULL, NULL}
	};

	for (i = 0; options[i].builtin != NULL; i++)
	{
		if (my_strcom(options[i].builtin, info->cmd_name, 0))
		{
			return (options[i].function(info));
		}
	}
	return (-1);
}
