#include "main.h"

/**
 *alias_print - nction is used to print out a list of aliases
 *		set in a shell
 *@info: pointer to struct containing the program's data
 *@alias: alias to be printed
 *Return: zero if sucess
 */
int alias_print(data_program *info, char *alias)
{
	int a, p;
	int length;
	char buffer[250] = {'\0'};

	if (info->list_alias)
	{
		length = my_strlen(alias);
		for (a = 0; info->list_alias[a]; a++)
		{
			if (!alias || (my_strcom(info->list_alias[a], alias, length)
				&&	info->list_alias[a][length] == '='))
			{
				for (p = 0; info->list_alias[a][p]; p++)
				{
					buffer[p] = info->alias_list[a][p];
					if (info->list_alias[a][p] == '=')
						break;
				}
				buffer[p + 1] = '\0';
				add_buff0(buffer, "'");
				add_buff0(buffer, info->list_alias[a] + p + 1);
				add_buff0(buffer, "'\n");
				_print(buffer);
			}
		}
	}

	return (0);
}

/**
 * alias_get - unction searches for a specific alias
 *		name in the data struct's list_alias
 * @info: struct for the program's data
 * @name: name of the alias.
 * Return: zero if sucess
 */
char *alias_get(data_program *info, char *name)
{
	int a, length;

	if (name == NULL || info->list_alias == NULL)
		return (NULL);

	length = my_strlen(name);
	for (a = 0; info->list_alias[a]; a++)
	{
		if (my_strcom(name, info->list_alias[a], length) &&
			info->list_alias[a][length] == '=')
		{
			return (info->list_alias[a] + length + 1);
		}
	}
	return (NULL);

}

/**
 * alias_set - sets an alias in the shell env
 * @alias_str: alias to be created in the form (name='value')
 * @info: Pointer to struct containing the program's data
 * Return: zero if sucess, or other number if its declared in the arguments
 */
int alias_set(char *alias_str, data_program *info)
{
	int a, p;
	char buffer[250] = {'0'};
	char *tempo = NULL;

	if (alias_str == NULL ||  info->list_alias == NULL)
		return (1);
	for (a = 0; alias_str[a]; a++)
		if (alias_str[a] != '=')
			buffer[a] = alias_str[a];
		else
		{
			tempo = alias_get(info, alias_str + a + 1);
			break;
		}

	for (p = 0; info->list_alias[p]; p++)
		if (my_strcom(buffer, info->list_alias[p], a) &&
			info->list_alias[p][a] == '=')
		{
			free(info->list_alias[p]);
			break;
		}

	if (tempo)
	{
		add_buff0(buffer, "=");
		add_buff0(buffer, tempo);
		info->list_alias[p] = my_strdup(buffer);
	}
	else
		info->list_alias[p] = my_strdup(alias_str);
	return (0);
}
