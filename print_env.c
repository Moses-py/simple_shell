#include "main.h"

extern char **environ;
void print_env()
{
	int i;
	for(i=0; environ[i]!=NULL; i++)
		printf("%d: %s\n", i, environ[i]);
}
