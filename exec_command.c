#include "main.h"

void exec_cmd(char **argv){
    char *command = NULL, *command_file_path = NULL, *exit_command = "exit", *env_command = "env";

    if (argv){
	    /* get the command */
	    command = argv[0];
	    if(strcmp(command, exit_command) == 0){
		    exit_shell();
	    }
	    if(strcmp(command, env_command) == 0)
	    {
	    	print_env();
	    }
	    
	    command_file_path = command_loc(command);
	    if (execve(command_file_path, argv, NULL) == -1)
		    perror("Error:");
    }

}

