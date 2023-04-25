#include "main.h"

/**
 *command_loc -function that searches for the command
 *		 in the system's PATH env variable
 *@user_command: name of command to be executed
 *Return: Success
 */

char *command_loc(char *user_command)
{
	char *env_path, *env_path_duplicate, *command_path;
	char *env_path_token;
	int command_length, token_length;
	struct stat buffer;

	env_path = getenv("PATH");
	if (env_path)
	{
		env_path_duplicate =  strdup(env_path);
		command_length = strlen(user_command);
		env_path_token = strtok(env_path_duplicate, ":");
		while (env_path_token != NULL)
		{
			token_length = strlen(env_path_token);
			command_path = malloc(command_length + token_length + 2);
			strcpy(command_path, env_path_token);
			strcat(command_path, "/");
			strcat(command_path, user_command);
			strcat(command_path, "\0");
			if (stat(command_path, &buffer) == 0)
			{
				free(env_path_duplicate);
				return (command_path);
			}
			else
			{
				free(command_path);
				env_path_token = strtok(NULL, ":");
			}
		}
		free(env_path_duplicate);
		if (stat(user_command, &buffer) == 0)
		{
			return (user_command);
		}
		return (NULL);
	}
	return (NULL);
}
