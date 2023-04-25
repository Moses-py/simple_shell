#include "main.h"

/**
 *exit_shell- function that exits a simple shell
 *@command_code: pointer to command code to be passed
 *Return: void
 */

void exit_shell(char *command_code)
{
	int status = 0;

	if (command_code != NULL)
	{
		status = string_to_int(command_code);
		printf("Shell disconnected---/\n");
		exit(status);
	}
	else
	{
		printf("Shell disconnected---/\n");
		exit(0);
	}
}
