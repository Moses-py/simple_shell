#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <signal.h>
#include <fcntl.h>

#include "macros.h"

/**
 * struct mssg- struct for the program's data
 * @exec_program: pointer to a string of chars containing executable
 *		names
 * @readin_put: pointer to a string of chars containing the
 *		 input read for get_line
 * @cmd_name: pointer to the char string that contains the
 *		first command inputted by the user
 * @num_cmd: num of executed commands
 * @file_des: file descrip to the commands inputted
 * @mytoken: pointer to an array of char pointer to commands that
 *		were tokenized
 * @envir: copy of the environ
 * @list_alias: pointer to an array of char pointers that contains
 *		the list of aliases.
 */

typedef struct mssg
{
	char *exec_program;
	char *readin_put;
	char *cmd_name;
	int num_cmd;
	int file_des;
	char **mytoken;
	char **envir;
	char **list_alias;
} data_program;

/**
 * struct builtins - the struct for the builtins
 * @builtin: the name of the builtin
 * @func: the associated function that
 *		implement to the builtin command
 */
typedef struct builtins
{
	char *builtin;
	int (*func)(data_program *info);
} builtins;

/*===== Main.c =====*/

void set_data(data_program *info, int arc, char *argv[], char **environ);

void prompt_loop(char *prompt, data_program *info);

void hd_crtl_c(int opr UNUSED);

/*===== getline_func.c =====*/

/* Read one line of the standard input*/
int getline_func(data_program *info);

/* split the each line for the logical operators if it exist */
int logic_ops(char *cmd_array[], int a, char op_array[]);


/*===== expand_func.c =====*/

/* expand variables */
void expand_var(data_program *info);

/* expand aliases */
void expand_alias(dataprogram *info);

/* append the string to the end of the buffer*/
int add_buff0(char *buffer, char *string);


/*===== strtok_func.c =====*/

/* Separate the string in tokens using a designed delimiter */
void break_string(data_program *info);

/* Creates a pointer to a part of a string */
char *_token(char *string, char *delim);


/*====== exec_func.c =====*/


/* Execute a command with its entire path */
int exec(data_program *info);


/*======== exec_builtins.c ========*/

/* If match a builtin, executes it */
int list_builtins(data_program *info);


/*======== path_find.c ========*/

/* Creates an array of the path directories */
char **break_path(data_program *info);

/* Search for program in path */
int program_fd(data_program *info);


/************** HELPERS FOR MEMORY MANAGEMENT **************/


/*======== myhelp_free.c ========*/

/* Frees the memory for directories */
void helpfree_arr(char **dir);

/* Free the fields needed each loop */
void helpfree_redata(data_program *info);

/* Free all field of the data */
void helpfree_alldata(data_program *info);


/************** BUILTINS **************/


/*======== miscell_builtins.c ========*/

/* Close the shell */
int exit_func(data_program *info);

/* Change the current directory */
int curr_dir_builtin(data_of_program *data);

/* set the work directory */
int set_wd_builtin(data_program *info, char *next_dir);

/* show help information */
int help_builtin(data_program *info);

/* set, unset and show alias */
int alias_builtin(data_program *info);


/*======== environ_builtins.c ========*/

/* Shows the environment where the shell runs */
int environ_builtin(data_program *info);

/* create or override a variable of environment */
int set_environ_builtin(data_program *info);

/* delete a variable of environment */
int unset_env_builtin(data_program *info);


/************** HELPERS FOR ENVIRONMENT VARIABLES MANAGEMENT **************/


/*======== env_management.c ========*/

/* Gets the value of an environment variable */
char *getval_env(char *name, data_program *info);

/* Overwrite the value of the environment variable */
int setenv_env(char *k, char *value, data_program *info);

/* Remove a key from the environment */
int remove_env(char *k, data_program *info);

/* prints the current environ */
void prt_env(data_program *info);


/************** HELPERS FOR PRINTING **************/


/*======== print_help_func.c ========*/

/* Prints a string in the standard output */
int _print(char *str);

/* Prints a string in the standar error */
int _printe(char *str);

/* Prints a string in the standar error */
int _perror(int errormssg, data_program *info);


/************** HELPERS FOR STRINGS MANAGEMENT **************/


/*======== string_help_func.c ========*/

/* Counts the number of characters of a string */
int my_strlen(char *str);

/* Duplicates an string */
char *my_strdup(char *str);

/* Compares two strings */
int *my_strcom(char *str1, char *str2, int diff);

/* Concatenates two strings */
char *my_strconcat(char *str1, char *str2);

/* Reverse a string */
void my_strreverse(char *str);


/*======== nums_help.c ========*/

/* Cast from int to string */
void long_str(long digit, char *str, int root);

/* convert an string in to a number */
int my_atoi(char *str);

/* count the coincidences of character in string */
int num_char(char *str, char *char);


/*======== alias_func.c ========*/

/* print the list of alias */
int alias_print(data_program *info, char *alias);

/* get the alias name */
char *alias_get(data_program *info, char *alias);

/* set the alias name */
int alias_set(char *alias_str, data_program *info);


#endif
