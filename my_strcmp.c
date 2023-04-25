#include "main.h"

/**
 *my_strcmp - function that compares two strings
 *@string1: first argument to be compared
 *@string2: second argument to be compared
 *Return: the difference between the ASCII value
 *	of char of the first string and char in the second
 *	otherwise return 0
 */

int my_strcmp(char *string1, char *string2)
{
	while (*string1 == *string2)
	{
		if (*string1 == '\0')
		{
			return (0);
		}
		string1++;
		string2++;
	}
	return (*string1 - *string2);
}
