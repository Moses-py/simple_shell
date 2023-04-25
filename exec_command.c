#include "main.h"

/**
 *exec_built_in -function that executes a command
 *		using the execuve system call
 *@command_path: pointer to string of PATH of the command to be executed
 *@argv: arguments received from command line
 *Return: void
 */

void exec_built_in(char *command_path, char **argv)
{
	if (execve(command_path, argv, NULL) == -1)
	perror("Error: ");
}

/**
 *exec_cmd -function that executes commands entered by the user
 *		with support for some built-in commands
 *@num_token: number of tokens inputted
 *@argv: token array
 *Return: void
 */

void exec_cmd(int num_token, char **argv)
{
	char *command = NULL, *command_file_path = NULL;
	char *exit_command = "exit";
	char *env_command = "env", *set_env_command = "setenv", *cd = "cd";
	int pid;

	if (argv)
	{
		command = argv[0];
		if (my_strcmp(command, exit_command) == 0)
		{
			exit_shell(argv[1]);
		}
		pid = fork();
		if (pid == -1)
		{
			exit(1);
		}
		else if (pid == 0)
		{
		if (my_strcmp(command, env_command) == 0)
			print_env();
		else if (my_strcmp(command, set_env_command) == 0)
			set_env(num_token, argv);
		else if (my_strcmp(command, cd) == 0)
			change_directory(num_token, argv);
		else
		{
			command_file_path = command_loc(command);
			exec_built_in(command_file_path, argv);
		}
		exit(0);
		}
		else
		{
		int status;

		wait(&status);
		}
	}
}
