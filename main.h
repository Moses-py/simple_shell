#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <errno.h>
#include <stdarg.h>
#include <stdbool.h>

void exec_cmd(int num_token, char **argv);
char * command_loc(char *user_command);
void exit_shell(char *command_code);
void print_env();
char *my_getline(void);
int string_to_int(char *str);
int my_strcmp(char *string1, char *string2);
int my_strncmp(char *string1, char *string2, size_t n);
void set_env(int num_args, char **argv);
int change_directory(int num_args, char **argv);
void _printf(char *format, ...);
