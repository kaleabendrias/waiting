#include "main.h"



/**
 * _setenv - handles the setenv command
 * @args: args
 * Return: none
 */
void _setenv(char **args)
{
	if (args[1] == NULL || args[2] == NULL)
	{
		write(STDERR_FILENO, "Usage: setenv VARIABLE VALUE\n", 29);
	}
	else if (setenv(args[1], args[2], 1) != 0)
	{
		write(STDERR_FILENO, "Failed to set environment variable\n", 35);
	}
}
