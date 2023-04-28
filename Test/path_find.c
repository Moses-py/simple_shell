#include "main.h"

int confirm_file(char *complete_path);

/**
 * program_fd - find a program in path
 * @info: a pointer to the program's data
 * Return: 0 if success, errcode otherwise
 */

int program_fd(data_program *info)
{
	int i = 0, rund_code = 0;
	char **dirs;

	if (!info->cmd_name)
		return (2);

	if (info->cmd_name[0] == '/' || info->cmd_name[0] == '.')
		return (confirm_file(info->cmd_name));

	free(info->mytoken[0]);
	info->mytoken[0] = my_strconcat(my_strdup("/"), info->cmd_name);
	if (!info->mytoken[0])
		return (2);

	dirs = break_path(info);

	if (!dirs || !dirs[0])
	{
		errno = 127;
		return (127);
	}
	for (i = 0; dirs[i]; i++)
	{
		dirs[i] = my_strconcat(dirs[i], info->mytoken[0]);

		rund_code = confirm_file(dirs[i]);

		if (rund_code == 0 || rund_code == 126)
		{
			errno = 0;
			free(info->mytoken[0]);
			info->mytoken[0] = my_strdup(dirs[i]);
			helpfree_arr(dirs);
			return (rund_code);
		}
	}
	free(info->mytoken[0]);
	info->mytoken[0] = NULL;
	helpfree_arr(dirs);
	return (rund_code);
}

/**
 * break_path - break the path in dirs
 * @info: a pointer to the program data
 * Return: return an array of path dirs
 */

char **break_path(data_program *info)
{
	int i = 0;
	int dir_count = 2;
	char **dir_tok = NULL;
	char *FULL;

	FULL = getval_env("PATH", info);
	if ((FULL == NULL) || FULL[0] == '\0')
	{
		return (NULL);
	}

	FULL = my_strdup(FULL);

	for (i = 0; FULL[i]; i++)
	{
		if (FULL[i] == ':')
			dir_count++;
	}

	dir_tok = malloc(sizeof(char *) * dir_count);

	i = 0;
	dir_tok[i] = my_strdup(_token(FULL, ":"));
	while (dir_tok[i++])
	{
		dir_tok[i] = my_strdup(_token(NULL, ":"));
	}

	free(FULL);
	FULL = NULL;
	return (dir_tok);
}

/**
 * confirm_file - checks if exists a file, if it is not a dir and
 * has excecution permisions.
 * @complete_path: pointer to complete file name
 * Return: 0 on success, or error if it exits.
 */

int confirm_file(char *complete_path)
{
	struct stat sb;

	if (stat(complete_path, &sb) != -1)
	{
		if (S_ISDIR(sb.st_mode) || access(complete_path, X_OK))
		{
			errno = 126;
			return (126);
		}
		return (0);
	}
	errno = 127;
	return (127);
}
