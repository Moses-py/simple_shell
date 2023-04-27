#include "main.h"

/**
 *main- function that prints user's input
 *Return: int
 */

int main(void)
{
	char *prompt = "simple_shell$ ", *line_pointer = NULL;
	char *token, *token_line_pointer_copy = NULL, *delim = " \n";
	size_t n = 0;
	ssize_t num_chars_read;
	int num_token = 0, i;
	char **argv;

	while (true)
	{
		_printf("%s", prompt);
		num_chars_read = getline(&line_pointer, &n, stdin);
	if (num_chars_read == -1)
	{
		printf("\nExiting shell ---/\n");
		return (-1);
	}
	token_line_pointer_copy = malloc(sizeof(char) * num_chars_read + 1);
	if (token_line_pointer_copy == NULL)
		return (-1);
	strcpy(token_line_pointer_copy, line_pointer);
	token = strtok(line_pointer, delim);
	while (token != NULL)
	{
		num_token++;
		token = strtok(NULL, delim);
	}
	argv = malloc(sizeof(char *) * num_token + 1);
	token = strtok(token_line_pointer_copy, delim);
	for (i = 0; token != NULL; i++)
	{
		argv[i] = malloc(sizeof(char) * strlen(token) + 1);
		strcpy(argv[i], token);
		token = strtok(NULL, delim);
	}
	argv[i] = NULL;
	exec_cmd(num_token, argv);
	}
	free(line_pointer);
	free(token_line_pointer_copy);
	return (0);
}
