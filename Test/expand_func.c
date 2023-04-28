#include "main.h"

/**
 * expand_var - function that expands variables
 * @info: a pointer to a struct of the program's data
 * Return: nothing, but sets errno.
 */

void expand_var(data_program *info)
{
	int a, p;
	char line[BUFFER_SIZE] = {0}, exp[BUFFER_SIZE] = {'\0'}, *tempo;

	if (info->readin_put == NULL)
		return;
	add_buff0(line, info->readin_put);
	for (a = 0; line[a]; a++)
		if (line[a] == '#')
			line[a--] = '\0';
		else if (line[a] == '$' && line[a + 1] == '?')
		{
			line[a] = '\0';
			long_str(errno, exp, 10);
			add_buff0(line, exp);
			add_buff0(line, info->readin_put + a + 2);
		}
		else if (line[a] == '$' && line[a + 1] == '$')
		{
			line[a] = '\0';
			long_str(getpid(), exp, 10);
			add_buff0(line, exp);
			add_buff0(line, info->readin_put + a + 2);
		}
		else if (line[a] == '$' && (line[a + 1] == ' ' || line[a + 1] == '\0'))
			continue;
		else if (line[a] == '$')
		{
			for (p = 1; line[a + p] && line[a + p] != ' '; p++)
				exp[p - 1] = line[a + p];
			tempo = getval_env(exp, info);
			line[a] = '\0', exp[0] = '\0';
			add_buff0(exp, line + a + p);
			tempo ? add_buff0(line, tempo) : 1;
			add_buff0(line, exp);
		}
	if (!my_strcom(info->readin_put, line, 0))
	{
		free(info->readin_put);
		info->readin_put = my_strdup(line);
	}
}

/**
 * expnd_alias - function that expands alias
 * @info: a pointer to a struct of the program's data
 * Return: nothing, but sets errno.
 */
void expnd_alias(data_program *info)
{
	int a, p, was_exp = 0;
	char line[BUFFER_SIZE] = {0}, exp[BUFFER_SIZE] = {'\0'}, *tempo;

	if (info->readin_put == NULL)
		return;

	add_buff0(line, info->readin_put);

	for (a = 0; line[a]; a++)
	{
		for (p = 0; line[a + p] && line[a + p] != ' '; p++)
			exp[p] = line[a + p];
		exp[p] = '\0';

		tempo = alias_get(info, exp);
		if (tempo)
		{
			exp[0] = '\0';
			add_buff0(exp, line + a + p);
			line[a] = '\0';
			add_buff0(line, tempo);
			line[my_strlen(line)] = '\0';
			add_buff0(line, exp);
			was_exp = 1;
		}
		break;
	}
	if (was_exp)
	{
		free(info->readin_put);
		info->readin_put = my_strdup(line);
	}
}

/**
 * add_buff0 - function that append string at end of the buffer
 * @buffer: buffer to be filled
 * @string: the str to be copied
 * Return: nothing, but sets errno.
 */
int add_buff0(char *buffer, char *string)
{
	int l, a;

	l = my_strlen(buffer);
	for (a = 0; string[a]; a++)
	{
		buffer[l + a] = string[a];
	}
	buffer[l + a] = '\0';
	return (l + a);
}
