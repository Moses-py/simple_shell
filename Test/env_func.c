#include "main.h"

/**
 * getval_env -function that gets the value of
 *		an environment variable
 * @k: the environment variable of interest
 * @info: pointer to the struct of the program's data
 * Return: a pointer to the value of the variable or NULL if it doesn't exist
 */
char *getval_env(char *k, data_program *info)
{
	int a, length = 0;

	if (k == NULL || info->envir == NULL)
		return (NULL);

	length = my_strlen(k);

	for (a = 0; info->envir[a]; a++)
	{
		if (my_strcom(k, info->envir[a], length) &&
		 info->envir[a][length] == '=')
		{
			return (info->envir[a] + length + 1);
		}
	}
	return (NULL);
}

/**
 * setenv_env - function overwrites the value of the environment variable
 * 		or create if it does not exist
 * @k: variable to be set
 * @value: new value
 * @info: pointer to the struct of the program's data
 * Return: 1 if the parameters are NULL, 2 if there is an erroror 0 if sucess.
 */
int setenv_env(char *k, char *value, data_program *info)
{
	int a, length = 0, new_key = 1;

	if (k == NULL || value == NULL || info->envir == NULL)
		return (1);

	length = my_strlen(k);

	for (a = 0; info->envir[a]; a++)
	{
		if (my_strcom(k, info->envir[a], length) &&
		 info->envir[a][length] == '=')
		{
			new_key = 0;
			free(info->envir[a]);
			break;
		}
	}
	info->envir[a] = my_strconcat(my_strdup(k), "=");
	info->envir[a] = my_strconcat(info->envir[a], value);

	if (new_key)
	{
		info->envir[a + 1] = NULL;
	}
	return (0);
}

/**
 * remove_env - function that removes a key from the environment
 * @k: key to be removed
 * @info: pointer to the struct of the program's data
 * Return: 1 if the key was removed,otherwise 0 if  key does not exist;
 */
int remove_env(char *k, data_program *info)
{
	int a, length = 0;

	if (k == NULL || info->envir == NULL)
		return (0);

	length = my_strlen(k);

	for (a = 0; info->envir[a]; a++)
	{
		if (my_strcom(k, info->envir[a], length) &&
		 info->envir[a][length] == '=')
		{
			free(info->envir[a]);

			a++;
			for (; info->envir[a]; a++)
			{
				info->envir[a - 1] = info->envir[a];
			}
			info->envir[a - 1] = NULL;
			return (1);
		}
	}
	return (0);
}


/**
 * prt_env -function that  prints the current environ
 * @info:pointer to the struct of the program's data
 * Return: nothing
 */
void prt_env(data_program *info)
{
	int p;

	for (p = 0; info->envir[p]; p++)
	{
		_print(info->envir[p]);
		_print("\n");
	}
}
