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
