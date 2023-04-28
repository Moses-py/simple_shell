#include "main.h"

/**
 * _print - writes a array of characters in the standar output
 * @str: pointer to the array of characters
 * Return: the number of bytes written or .
 * -1 if error, and errno.
 */
int _print(char *str)
{
	return (write(STDOUT_FILENO, str, my_strlen(str)));
}
/**
 * _printe - writes a array of characters in the standar error
 * @str: pointer to the array of characters
 * Return: the number of bytes written or .
 * -1 if error, and errno.
 */
int _printe(char *str)
{
	return (write(STDERR_FILENO, str, my_strlen(str)));
}

/**
 * _print_error - writes array of characters in the standart error
 * @info: a pointer to the program's info'
 * @errormssg: error code to print
 * Return: the number of bytes written or .
 * -1 if error, and errno.
 */
int _print_error(int errormssg, data_program *info)
{
	char num_str[10] = {'\0'};

	long_str((long)info->num_cmd, num_str, 10);

	if (errormssg == 2 || errormssg == 3)
	{
		_printe(info->exec_program);
		_printe(": ");
		_printe(num_str);
		_printe(": ");
		_printe(info->mytoken[0]);
		if (errormssg == 2)
			_printe(": Illegal number: ");
		else
			_printe(": can't cd to ");
		_printe(info->mytoken[1]);
		_printe("\n");
	}
	else if (errormssg == 127)
	{
		_printe(info->exec_program);
		_printe(": ");
		_printe(num_str);
		_printe(": ");
		_printe(info->cmd_name);
		_printe(": not found\n");
	}
	else if (errormssg == 126)
	{
		_printe(info->exec_program);
		_printe(": ");
		_printe(num_str);
		_printe(": ");
		_printe(info->cmd_name);
		_printe(": Permission denied\n");
	}
	return (0);
}
