#include "main.h"

/**
*getline_func - function that reads a line of input
*@info: pointer to struct containing thr program's data
*Return: length of next command
*/
int getline_func(data_program *info)
{
	ssize_t nreads_bytes, a = 0;
	char buff[BUFFER_SIZE] = {'\0'};
	static char *cmd_array[10] = {NULL};
	static char op_array[10] = {'\0'};


	if (!cmd_array[0] || (op_array[0] == '&' && errno != 0) ||
		(op_array[0] == '|' && errno == 0))
	{
		for (a = 0; cmd_array[a]; a++)
		{
			free(cmd_array[a]);
			cmd_array[a] = NULL;
		}

		nreads_bytes = read(info->file_des, &buff, BUFFER_SIZE - 1);
		if (nreads_bytes == 0)
			return (-1);

		a = 0;
		do {
			cmd_array[a] = my_strdup(my_strtok(a ? NULL : buff, "\n;"));
			a = logic_ops(cmd_array, a, op_array);
		} while (cmd_array[a++]);
	}

	info->readin_put = cmd_array[0];
	for (a = 0; cmd_array[a]; a++)
	{
		cmd_array[a] = cmd_array[a + 1];
		op_array[a] = op_array[a + 1];
	}

	return (my_strlen(info->readin_put));
}


/**
*logic_ops - function checks for and split the logical operators
*		'&&' and '||' operators
*@cmd_array: array of strings of commands
*@a: current index in the cmd_array to be checked
*@op_array: array of chars that stores the logical operators
* Return: index of the last command in the cmd_array
*/
int logic_ops(char *cmd_array[], int a, char op_array[])
{
	char *tempo = NULL;
	int p;

	for (p = 0; cmd_array[a] != NULL  && cmd_array[a][p]; p++)
	{
		if (cmd_array[a][p] == '&' && cmd_array[a][p + 1] == '&')
		{
			tempo = cmd_array[a];
			cmd_array[a][p] = '\0';
			cmd_array[a] = my_strdup(cmd_array[a]);
			cmd_array[a + 1] = my_strdup(tempo + p + 2);
			a++;
			op_array[a] = '&';
			free(tempo);
			p = 0;
		}
		if (cmd_array[a][p] == '|' && cmd_array[a][p + 1] == '|')
		{
			tempo = cmd_array[a];
			cmd_array[a][p] = '\0';
			cmd_array[a] = my_strdup(cmd_array[a]);
			cmd_array[a + 1] = my_strdup(tempo + p + 2);
			a++;
			op_array[a] = '|';
			free(tempo);
			p = 0;
		}
	}
	return (a);
}
