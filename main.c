#include "main.h"

int main(void){
  char *prompt="simple_shell$ ",*line_pointer,*token,*token_line_pointer_copy;
  size_t n = 0;
  ssize_t num_chars_read;
  int num_token = 0, i;
  char **argv;

  while(true) {
  	_printf("%s", prompt);
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
	argv = malloc(sizeof(char *) * num_token);
	token = strtok(token_line_pointer_copy, " \n");
	for (i = 0; token !=NULL; i++)
	{
		argv[i] = malloc(sizeof(char) * strlen(token));
		strcpy(argv[i], token);
		token = strtok(NULL, " \n");
	}
	argv[i] = NULL;
	exec_cmd(num_token,argv);
  }
  free(line_pointer);
  free(token_line_pointer_copy);
  return (0);
}
