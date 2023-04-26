#include "main.h"

/**
 *set_env- function that sets an environment variable
 *with a given name ande value
 *@num_args: number of arguments
 *@argv: array of string
 *Return: void
 */

void set_env(int num_args, char **argv)
{
	char *envi = NULL;

	if (argv)
	{
		if (num_args != 3)
		{
			fprintf(stderr, "Usage: %s VARIABLE VALUE\n", argv[0]);
			exit(1);
		}
		else
		{
			if (setenv(argv[1], argv[2], 1) != 0)
			{
				fprintf(stderr, "%s: %s\n", argv[0], strerror(errno));
				exit(1);
			}
			else
			{
				envi = getenv(argv[1]);
				printf("%s\n", envi);
			}

		}

	}

}
