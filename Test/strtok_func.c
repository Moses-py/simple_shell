#include "main.h"
/**
 * my_strtok - separates strings with delimiters
 * @string: It´s pointer to array we receive in getstring.
 * @delim: It´s characters we mark off string in parts.
 * Return: A pointer to the created token
 */
char *my_strtok(char *string, char *delim)
{
	int index;
	static char *str;
	char *dup_str;

	if (string != NULL)
		str = string;
	for (; *str != '\0'; str++)
	{
		for (index = 0; delim[index] != '\0'; index++)
		{
			if (*str == delim[index])
				break;
		}
		if (delim[index] == '\0')
			break;
	}
	dup_str = str;
	if (*dup_str == '\0')
		return (NULL);
	for (; *str != '\0'; str++)
	{
		for (index = 0; delim[index] != '\0'; index++)
		{
			if (*str == delim[index])
			{
				*str = '\0';
				str++;
				return (dup_str);
			}
		}
	}
	return (dup_str);
}
