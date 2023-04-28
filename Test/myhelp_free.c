#include "main.h"

/**
 * helpfree_redata - function that frees the fields needed each loop
 * @info: pointer to the struct of the program's data
 * Return: Nothing
 */
void helpfree_redata(data_program *info)
{
	if (info->mytoken)
		helpfree_arr(info->mytoken);
	if (info->readin_put)
		free(info->readin_put);
	if (info->cmd_name)
		free(info->cmd_name);

	info->readin_put = NULL;
	info->cmd_name = NULL;
	info->mytoken = NULL;
}

/**
 * helpfree_alldata -function that frees all field of the data
 * @info: pointer to the struct of the program's data
 * Return: Nothing
 */
void helpfree_alldata(data_program *info)
{
	if (info->file_des != 0)
	{
		if (close(info->file_des))
			perror(info->exec_program);
	}
	helpfree_redata(info);
	helpfree_arr(info->envir);
	helpfree_arr(info->list_alias);
}

/**
 * helpfree_arr - function that frees each
 * pointer of an array of pointers and the
 * array too
 * @arr: the array of pointers
 * Return: nothing
 */
void helpfree_arr(char **arr)
{
	int a;

	if (arr != NULL)
	{
		for (a = 0; arr[a]; a++)
			free(arr[a]);

		free(arr);
		arr = NULL;
	}
}
