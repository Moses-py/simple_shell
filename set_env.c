#include "main.h"
void set_env(int num_args, char **argv)
{
    if(argv)
    {
        if (num_args != 3) {
            fprintf(stderr, "Usage: %s VARIABLE VALUE\n", argv[0]);
            exit(1);
        }else {
            if (setenv(argv[1], argv[2], 1) != 0) {
                fprintf(stderr, "%s: %s\n", argv[0], strerror(errno));
                exit(1);
            }
        }
    }
}
