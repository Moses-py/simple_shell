#include "main.h"

/**
 * long_str - converts a digit to a str.
 * @digit: digit to be converten in an str.
 * @str: buffer to save the digit as str.
 * @root: root to convert digit
 * Return: Nothing.
 */
void long_str(long digit, char *str, int root)
{
	int i = 0, neg = 0;
	long coc = digit;
	char alpha[] = {"0123456789abcdef"};

	if (coc == 0)
		str[i++] = '0';

	if (str[0] == '-')
		neg = 1;

	while (coc)
	{
		if (coc < 0)
			str[i++] = alpha[-(coc % root)];
		else
			str[i++] = alpha[coc % root];
		coc /= root;
	}
	if (neg)
		str[i++] = '-';

	str[i] = '\0';
	my_strreverse(str);
}

/**
 * my_atoi - convert a str to an integer.
 * @s: pointer to str origen.
 * Return: int of str or 0.
 */
int my_atoi(char *str)
{
	int sign = 1;
	unsigned int digit = 0;
	/*1- analisys sign*/
	while (!('0' <= *str && *str <= '9') && *str != '\0')
	{
		if (*str == '-')
			sign *= -1;
		if (*str == '+')
			sign *= +1;
		str++;
	}

	while ('0' <= *str && *str <= '9' && *str != '\0')
	{

		digit = (digit * 10) + (*str - '0');
		str++;
	}
	return (digit * sign);
}

/**
 * num_char - count the coincidences of char in str.
 * @str: pointer to str origen.
 * @char: str with  chars to be counted
 * Return: int of str or 0.
 */
int num_char(char *str, char *char)
{
	int index = 0, iterator = 0;

	for (; str[index]; index++)
	{
		if (str[index] == char[0])
			iterator++;
	}
	return (iterator);
}
