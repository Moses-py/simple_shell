#include "main.h"

/**
 * my_strlen - returns the len of a str.
 * @str: pointer to str.
 * Return: len of str.
 */
int my_strlen(char *str)
{
	int len = 0;

	if (str == NULL)
		return (0);

	while (str[len++] != '\0')
	{
	}
	return (--len);
}

/**
 * my_strdup - duplicates an str
 * @str: str to be copied
 * Return: pointer to the array
 */
char *my_strdup(char *str)
{
	char *dup;
	int len, i;

	if (str == NULL)
		return (NULL);

	len = my_strlen(str) + 1;

	dup = malloc(sizeof(char) * len);

	if (dup == NULL)
	{
		errno = ENOMEM;
		perror("Error");
		return (NULL);
	}
	for (i = 0; i < len; i++)
	{
		dup[i] = str[i];
	}

	return (dup);
}

/**
 * my_strcom - Compare two strs
 * @str1: str one, or the shorter
 * @str2: str two, or the longer
 * @diff: diff of characters to be compared, 0 if infinite
 * Return: 1 if the strs are equals,0 if the strs are different
 */
int my_strcom(char *str1, char *str2, int diff)
{
	int count;

	if (str1 == NULL && str2 == NULL)
		return (1);

	if (str1 == NULL || str2 == NULL)
		return (0);

	if (diff == 0) /* infinite longitud */
	{
		if (my_strlen(str1) != my_strlen(str2))
			return (0);
		for (count = 0; str1[count]; count++)
		{
			if (str1[count] != str2[count])
				return (0);
		}
		return (1);
	}
	else /* if there is a diff of chars to be compared */
	{
		for (count = 0; count < diff; count++)
		{
			if (str1[count] != str2[count])
				return (0);
		}
		return (1);
	}
}

/**
 * my_strconcat - concatenates two strs.
 * @str1: str to be concatenated
 * @str2: str to be concatenated
 *
 * Return: pointer to the array
 */
char *my_strconcat(char *str1, char *str2)
{
	char *dup;
	int len1 = 0, len2 = 0;

	if (str1 == NULL)
		str1 = "";
	len1 = my_strlen(str1);

	if (str2 == NULL)
		str2 = "";
	len2 = my_strlen(str2);

	dup = malloc(sizeof(char) * (len1 + len2 + 1));
	if (dup == NULL)
	{
		errno = ENOMEM;
		perror("Error");
		return (NULL);
	}

	/* copy of str1 */
	for (len1 = 0; str1[len1] != '\0'; len1++)
		dup[len1] = str1[len1];
	free(str1);

	/* copy of str2 */
	for (len2 = 0; str2[len2] != '\0'; len2++)
	{
		dup[len1] = str2[len2];
		len1++;
	}

	dup[len1] = '\0';
	return (dup);
}

/**
 * my_strreverse - reverses a str.
 *
 * @str: pointer to str.
 * Return: void.
 */
void my_strreverse(char *str)
{

	int i = 0, len = my_strlen(str) - 1;
	char temporary;

	while (i < len)
	{
		temporary = str[i];
		str[i++] = str[len];
		str[len--] = temporary;
	}
}
