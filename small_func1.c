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

