#include "main.h"

/**
 *environ_builtin - function allows user view and modify
 *	the environment variables
 * @info:Pointer to struct containing the program's data
 * Return: zero if sucess, or other num if declared in args
 */
int environ_builtin(data_program *info)
{
	int a;
	char tp[50] = {'\0'};
	char *cp_var = NULL;

	if (info->mytoken[1] == NULL)
		prt_env(info);
	else
	{
		for (a = 0; info->mytoken[1][a]; a++)
		{
			if (info->mytoken[1][a] == '=')
			{
				cp_var = my_strdup(getval_env(tp, info));
				if (cp_var != NULL)
					setenv_env(tp, info->my_token[1] + a + 1, info);

				prt_env(info);
				if (getval_env(tp, info) == NULL)
				{
					_print(info->mytoken[1]);
					_print("\n");
				}
				else
				{
					setenv_env(tp, cp_var, info);
					free(cp_var);
				}
				return (0);
			}
			tp[a] = info->my_token[1][a];
		}
		errno = 2;
		perror(info->cmd_name);
		errno = 127;
	}
	return (0);
}

/**
 * set_environ_builtin - allows user to set and modify environ
 * @info: Pointer to struct containing the program's data
 * Return: zero if sucess, otherwise another number if failed
 */
int set_environ_builtin(data_program *info)
{

	if (info->mytoken[1] == NULL || info->mytoken[2] == NULL)
		return (0);
	if (info->mytoken[3] != NULL)
	{
		errno = E2BIG;
		perror(info->cmd_name);
		return (5);
	}

	setenv_env(info->mytoken[1], info->mytoken[2], info);

	return (0);
}

/**
 *unset_env_builtin -function allows user remove an env variable
 * @info:Pointer to struct containing the program's data
 * Return: ..
 */
int unset_env_builtin(data_program *info)
{
	if (info->mytoken[1] == NULL)
		return (0);
	if (info->mytoken[2] != NULL)
	{
		errno = E2BIG;
		perror(info->cmd_name);
		return (5);
	}
	remove_env(info->mytoken[1], info);

	return (0);
}
