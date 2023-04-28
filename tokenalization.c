#include "main.h"
/**
 * tokenalization- this function breaks the string using a delim
 * @info: a pointer to the program's info
 * Return: an array of the separated string
 */
void tokenalization(data_program *info)
{
	char *delim = " \t";
	int i, x, iterator = 2, len;

	len = my_strlen(info->readin_put);
	if (len)
	{
		if (info->readin_put[len - 1] == '\n')
			info->readin_put[len - 1] = '\0';
	}

	for (i = 0; info->readin_put[i]; i++)
	{
		for (x = 0; delim[x]; x++)
		{
			if (info->readin_put[i] == delim[x])
				iterator++;
		}
	}

	info->mytoken = malloc(iterator * sizeof(char *));
	if (info->mytoken == NULL)
	{
		perror(info->exec_program);
		exit(errno);
	}
	i = 0;
	info->mytoken[i] = my_strdup(my_strtok(info->readin_put, delim));
	info->cmd_name = my_strdup(info->mytoken[0]);
	while (info->mytoken[i++])
	{
		info->mytoken[i] = my_strdup(my_strtok(NULL, delim));
	}
}
