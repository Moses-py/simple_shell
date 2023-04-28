#include "main.h"

/**
 * exec - execute a command with its entire path variables
 * @info: Pointer to struct containing the program's data
 * Return: If sucessful returns 0, otherwise, return -1.
 */
int exec(data_program *info)
{
	int rvalue = 0, stat;
	pid_t prID;

	rvalue = list_builtins(info);
	if (rvalue != -1)
		return (rvalue);

	rvalue = program_fd(info);
	if (rvalue)
	{
		return (rvalue);
	}
	else
	{
		prID = fork();
		if (prID == -1)
		{
			perror(info->cmd_name);
			exit(EXIT_FAILURE);
		}
		if (prID == 0)
		{
			rvalue = execve(info->mytoken[0], info->mytoken, info->envir);
			if (rvalue == -1)
				perror(info->cmd_name), exit(EXIT_FAILURE);
		}
		else
		{
			wait(&stat);
			if (WIFEXITED(stat))
				errno = WEXITSTATUS(stat);
			else if (WIFSIGNALED(stat))
				errno = 128 + WTERMSIG(stat);
		}
	}
	return (0);
}
