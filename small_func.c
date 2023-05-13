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

char *_strtok(char *str, const char *delimiters) {
    static char *next_t = NULL;
    char *token_s, *token_e;


    if (str != NULL) {
        next_t = str;
    }
    if (next_t == NULL || *next_t == '\0') {
        return NULL;
    }
    token_s = next_t;
    token_e = next_t;

    while (*token_e != '\0') {
        if (_strchr(delimiters, *token_e) != NULL) {
            *token_e = '\0';
            next_t = token_e + 1;
            if (*next_t != '\0') {
                return token_s;
            } else {
                next_t = NULL;
                return token_s;
            }
        }
        token_e++;
    }
    next_t = NULL;
    return token_s;
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

/**
 * _strcpy - main
 * @dest: destination
 * @src: source
 * Return: none
 */

void _strcpy(char *dest, const char *src)
{
	int i = 0;

	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

/**
 * _strcat - does function of strcat
 * @dest: destination
 * @src: source
 * Return: none
 */

void _strcat(char *dest, const char *src)
{
	int dest_len, i;

	dest_len = 0;
	while (dest[dest_len] != '\0')
		dest_len++;
	i = 0;
	while (src[i] != '\0')
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';
}
