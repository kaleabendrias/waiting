#include "main.h"

#define MAX_ARGS 64
#define PROMPT "$"

int tokenize_input(char *input, char **args)
{
	int argc;
	char *token;

	argc = 0;
	token = _strtok(input, " \n");
	while (token != NULL & argc < MAX_ARGS - 1)
	{
		args[argc++] = token;
		token = _strtok(NULL, " \n");
	}
	args[argc] = NULL;
	return (argc);
}

int main()
{
	char *getcom = NULL;
	size_t n = 0;
	ssize_t n_char;
	char *args[MAX_ARGS];
	int argc;

	while (1)
	{
		write(STDOUT_FILENO, PROMPT, _strlen(PROMPT));
		n_char = getline(&getcom, &n, stdin);
		if (n_char == -1)
			break;
		argc = tokenize_input(getcom, args);
		exe(args);
	}
	return (0);
}
