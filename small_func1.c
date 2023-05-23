#include "main.h"

/**
 * _strdup - main
 * @src: source
 * Return: Always
 */

char *_strdup(const char *src)
{
	int len, i;
	char *dest;

	len = 0;
	while (src[len] != '\0')
		len++;
	dest = (char *)malloc((len + 1) * sizeof(char));
	if (dest == NULL)
		return (NULL);
	for (i = 0; i <= len; i++)
		dest[i] = src[i];
	return (dest);
}

/**
 * _strcmp - does the function of strcmp
 * @str1: string 1
 * @str2: string 2
 * Return: Always
 */

int _strcmp(const char *str1, const char *str2)
{
	while (*str1 && (*str1 == *str2))
	{

		str1++;
		str2++;
	}
	return (*(unsigned char *) str1 - *(unsigned char *)str2);
}

/**
 * isDelimiter - check if it is delimiter
 * @c: char
 * @delimiters: bunch of delimeters
 * Return: Alwyas
 */

unsigned int isDelimiter(char c, const char *delimiters)
{
	unsigned int index;

	for (index = 0; delimiters[index] != '\0'; index++)
	{
		if (c == delimiters[index])
			return (1);
	}
	return (0);
}

/**
 * _atoi - converts string to intiger
 * @s: the string convert
 * Return: the converted string.
 */

int _atoi(const char *s)
{
	int res, sign, idx;

	res = 0;
	sign = 1;
	idx = 0;

	if (s[0] == '-')
	{
		sign = -1;
		idx++;
	}
	while (s[idx] != '\0')
	{
		if (s[idx] >= '0' && s[idx] <= '9')
			res = res * 10 + (s[idx] - '0');
		else
			break;
		idx++;
	}
	return (res * sign);
}

