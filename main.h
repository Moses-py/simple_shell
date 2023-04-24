#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

void exec_cmd(char **argv);
char * command_loc(char *user_command);
void exit_shell();
void print_env();
size_t my_getline(char **lineptr);
