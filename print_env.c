#include "main.h"

/**
 *print_env - function prints the environment variables
 *		 and its values
 *Return: void
 */

void print_env(void)
{
	int i;

	for (i = 0; environ[i] != NULL; i++)
		printf("%d: %s\n", i, environ[i]);
}
