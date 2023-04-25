#include "main.h"i

/**
 *my_strncmp - function that compares number of chars
 *		in 2 strings
 *@string1: first string to be compared
 *@string2: second string to be compared
 *@n: number of chars
 *Return: 0 otherwise the difference btw the ASCII values
 *	of the non-matching char in both strings
 */

int my_strncmp(char *string1, char *string2, size_t n)
{
	while (n > 0)
	{
		if (*string1 == '\0' || *string1 != *string2)
		{
			return (*string1 - *string2);
		}
		string1++;
		string2++;
		n--;
	}
	return (0);
}
