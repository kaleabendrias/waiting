#include "main.h"

/**
 * _strchr - searches for characters march
 * @str: the char
 * @character: currentchar
 * Return: Always.
 */

char *_strchr(const char *str, int character)
{
	while (*str != '\0')
	{
		if (*str == character)
		{
			return ((char *) str);
		}
		str++;
	}
	if (character == '\0')
		return ((char *) str);
	return (NULL);
}

/**
 * _strtok - mimics strtok
 * @s: string
 * @d: dellimiter
 * Return: always
 */

char *_strtok(char *s, const char *d)
{
	static char *next_t;
	char *token_s, *token_e;

	next_t = NULL;
	if (s != NULL)
		next_t = s;
	if (next_t == NULL || *next_t == '\0')
		return (NULL);
	token_s = next_t;
	token_e = next_t;
	while (*token_e != '\0')
	{
		if (_strchr(d, *token_e) != NULL)
		{
			*token_e = '\0';
			next_t = token_e + 1;
			if (*next_t != '\0')
			{
				return (token_s);
			}
			else
			{
				next_t = NULL;
				return (token_s);
			}
		}
		token_e++;
	}
	next_t = NULL;
	return (token_s);
}

/**
 * _strlen - returns the length of string
 * @arg: string
 * Return: always
 */

int _strlen(const char *arg)
{
	int len;

	len = 0;
	while (*arg != '\0')
	{
		len++;
		arg++;
	}
	return (len);
}
