#include "main.h"

/**
 * main - initialize the variables of the program
 * @argc: number of values received from the command line
 * @argv: values received from the command line
 * @env: number of values received from the command line
 * Return: zero on succes.
 */
int main(int argc, char *argv[], char *env[])
{
	data_program structure = {NULL}, *info = &structure;
	char *shell_prompt = "";

	set_data(info, argc, argv, env);

	signal(SIGINT, hd_crtl_c);

	if (isatty(STDIN_FILENO) && isatty(STDOUT_FILENO) && argc == 1)
	{
		errno = 2;
		shell_prompt = PROMPT_MSG;
	}
	errno = 0;
	prompt_loop(shell_prompt, info);
	return (0);
}

/**
 * hd_crtl_c - print the shell_prompt in a new line
 * when the signal SIGINT (ctrl + c) is send to the program
 * @UNUSED: option of the prototype
 */
void hd_crtl_c(int opr UNUSED)
{
	_print("\n");
	_print(PROMPT_MSG);
}

/**
 * set_data - inicialize the struct with the info of the program
 * @info: pointer to the structure of info
 * @argv: array of arguments pased to the program execution
 * @env: environ pased to the program execution
 * @argc: number of values received from the command line
 */
void set_data(data_program *info, int argc, char *argv[], char **env)
{
	int i = 0;

	info->exec_program = argv[0];
	info->readin_put = NULL;
	info->cmd_name = NULL;
	info->num_cmd = 0;
	if (argc == 1)
		info->file_des = STDIN_FILENO;
	else
	{
		info->file_des = open(argv[1], O_RDONLY);
		if (info->file_des == -1)
		{
			_printe(info->exec_program);
			_printe(": 0: Can't open ");
			_printe(argv[1]);
			_printe("\n");
			exit(127);
		}
	}
	info->mytoken = NULL;
	info->envir = malloc(sizeof(char *) * 50);
	if (env)
	{
		for (; env[i]; i++)
		{
			info->envir[i] = my_strdup(env[i]);
		}
	}
	info->envir[i] = NULL;
	env = info->envir;

	info->list_alias = malloc(sizeof(char *) * 20);
	for (i = 0; i < 20; i++)
	{
		info->list_alias[i] = NULL;
	}
}
/**
 * prompt_loop - its a infinite loop that shows the shell_prompt
 * @shell_prompt: shell_prompt to be printed
 * @info: its a infinite loop that shows the shell_prompt
 */
void prompt_loop(char *shell_prompt, data_program *info)
{
	int error_code = 0, string_len = 0;

	while (++(info->num_cmd))
	{
		_print(shell_prompt);
		error_code = string_len = getline_func(info);

		if (error_code == EOF)
		{
			helpfree_alldata(info);
			exit(errno);
		}
		if (string_len >= 1)
		{
			expnd_alias(info);
			expand_var(info);
			tokenalization(info);
			if (info->mytoken[0])
			{
				error_code = exec(info);
				if (error_code != 0)
					_print_error(error_code, info);
			}
			helpfree_redata(info);
		}
	}
}
