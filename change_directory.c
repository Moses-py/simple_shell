#include "main.h"

int change_directory(int num_args, char **argv)
{
    char *new_working_directory = NULL, *dir = NULL, *cur_working_directory = NULL, *old_working_directory = getenv("OLDPWD"), *home_directory = getenv("HOME");
    int result;

    if (num_args == 1) {
        dir = home_directory;
    }
    else if (my_strcmp(argv[1], "-") == 0) {
        dir = old_working_directory;
    }
    else {
        dir = argv[1];
    }
    cur_working_directory = getcwd(NULL, 0);
    if (cur_working_directory == NULL) {
        perror("getcwd");
        return 1;
    }
    result = chdir(dir);
    if (result != 0) {
        perror(dir);
        return 1;
    }
    new_working_directory = getcwd(NULL, 0);
    if (new_working_directory == NULL) {
        perror("getcwd");
        return 1;
    }
    result = setenv("OLDPWD", cur_working_directory, 1);
    if (result != 0) {
        perror("setenv");
        return 1;
    }
    result = setenv("PWD", new_working_directory, 1);
    if (result != 0) {
        perror("setenv");
        return 1;
    }
    printf("%s\n", new_working_directory);
    free(cur_working_directory);
    free(new_working_directory);
    return 0;
}
