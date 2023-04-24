#include "main.h"
#include <stdbool.h>

int main(void){
  char *prompt = "simple_shell $ ";
  char *line_pointer;
  size_t n = 0;
  ssize_t num_chars_read;
  char *token_line_pointer_copy;
  char *token;
  int num_token = 0;
  char **argv;
  int i;

  while(true) {
  	printf("%s", prompt);

	num_chars_read = getline(&line_pointer, &n, stdin);
	
	if (num_chars_read == -1)
	{
		printf("\nExiting shell ---/\n");
		return (-1);
	}

	token_line_pointer_copy = malloc(sizeof(char) * num_chars_read);

	if (token_line_pointer_copy == NULL)
	{
		perror("Memory allocation error");
		return (-1);
	}
	
	strcpy(token_line_pointer_copy, line_pointer);

	token = strtok(line_pointer, " \n");

	while(token != NULL)
	{
		num_token++;
		token = strtok(NULL, " \n");
	}
	num_token++;

	argv = malloc(sizeof(char *) * num_token);

	token = strtok(token_line_pointer_copy, " \n");

	for (i = 0; token !=NULL; i++)
	{
		argv[i] = malloc(sizeof(char) * strlen(token));
		strcpy(argv[i], token);

		token = strtok(NULL, " \n");

	}
	argv[i] = NULL;
	
	exec_cmd(argv);
  }

  free(line_pointer);
  free(token_line_pointer_copy);

  return (0);
}


