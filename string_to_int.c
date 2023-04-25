#include "main.h"

/**
 *string_to_int - function that takes an argument
 *		converts it to an int value
 *@str: pointer to character array
 *Return: int value of input string
 */

int string_to_int(char *str)
{
	int code = 0;
	int sign = 1;

	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	while (*str != '\0')
	{
		if (*str < '0' || *str > '9')
		{
			return (0);
		}
		code = code * 10 + (*str - '0');
		str++;
	}
	return (sign * code);
}
