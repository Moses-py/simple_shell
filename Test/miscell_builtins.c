#include "main.h"

/**
 *exit_func - function exit of the program with the status
 *@info: Pointer to struct containing the program's data
 * Return: zero if sucess,otherwise other num as declard
 */
int exit_func(data_program *info)
{
	int a;

	if (info->mytoken[1] != NULL)
	{
		for (a = 0; info->mytoken[1][a]; a++)
			if ((info->mytoken[1][a] < '0' || info->mytoken[1][a] > '9')
				&& info->mytoken[1][a] != '+')
			{
				errno = 2;
				return (2);
			}
		errno = my_atoi(info->mytoken[1]);
	}
	helpfree_alldata(info);
	exit(errno);
}

/**
 * curr_dir_builtin - function that changes the current directory
 * @info: Pointer to struct containing the program's data
 * Return: zero if sucess, otherwise other num as declared
 */
int curr_dir_builtin(data_program *info)
{
	char *directory_hm = getval_env("HOME", info);
	char *directory_old = NULL;
	char old_directory[128] = {0};
	int error_mssg = 0;

	if (info->mytoken[1])
	{
		if (my_strcom(info->mytoken[1], "-", 0))
		{
			directory_old = getval_env("OLDPWD", info);
			if (directory_old)
				error_mssg = set_wd_builtin(info, directory_old);
			_print(getval_env("PWD", info));
			_print("\n");

			return (error_mssg);
		}
		else
		{
			return (set_wd_builtin(info, info->mytoken[1]));
		}
	}
	else
	{
		if (!directory_hm)
			directory_hm = getcwd(old_directory, 128);

		return (set_wd_builtin(info, directory_hm));
	}
	return (0);
}

/**
 * set_wd_builtin - function that sets the working directory
 *@info:Pointer to struct containing the program's data
 *@new_directory: the path to set
 * Return: zero if sucess, otherwise other num as declared
 */
int set_wd_builtin(data_program *info, char *new_directory)
{
	char old_directory[128] = {0};
	int err_mssg = 0;

	getcwd(old_directory, 128);

	if (!my_strcom(old_directory, new_directory, 0))
	{
		err_mssg = chdir(new_directory);
		if (err_cmssg == -1)
		{
			errno = 2;
			return (3);
		}
		setenv_env("PWD", new_directory, info);
	}
	setenv_env("OLDPWD", old_directory, info);
	return (0);
}

/**
 * help_builtin -the function that implements a built-in
 *		 "help" command for a shell
 * @info: Pointer to struct containing the program's data
 * Return: zero if sucess, otherwise other num as declared
 */
int help_builtin(data_program *info)
{
	int a, l = 0;
	char *mssg[6] = {NULL};

	mssg[0] = HELP_MSG;

	if (info->mytoken[1] == NULL)
	{
		_print(mssg[0] + 6);
		return (1);
	}
	if (info->mytoken[2] != NULL)
	{
		errno = E2BIG;
		perror(info->cmd_name);
		return (5);
	}
	mssg[1] = HELP_EXIT_MSG;
	mssg[2] = HELP_ENV_MSG;
	mssg[3] = HELP_SETENV_MSG;
	mssg[4] = HELP_UNSETENV_MSG;
	mssg[5] = HELP_CD_MSG;

	for (a = 0; mssg[a]; a++)
	{
		l = my_strlen(info->mytoken[1]);
		if (my_strcom(info->mytoken[1], mssg[0], l))
		{
			_print(mssg[a] + l + 1);
			return (1);
		}
	}
	errno = EINVAL;
	perror(info->cmd_name);
	return (0);
}

/**
 * alias_builtin- fnction that implement the alias command
 * @info: Pointer to struct containing the program's data
 * Return: zero if sucess, otherwise other num as declared
 */

{
	int a = 0;

	if (info->mytoken[1] == NULL)
		return (alias_print(info, NULL));

	while (info->mytoken[++a])
	{
		if (num_char(info->mytoken[a], "="))
			alias_set(info->mytoken[a], info);
		else
			alias_print(info, info->mytoken[a]);
	}

	return (0);
}
