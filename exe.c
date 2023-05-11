#include "main.h"

/**
 * exe - executes the commands
 * @args: args
 * Return: none
 */

void exe(char **args)
{
	char *command;
	char *error_msg;
	pid_t pid;
	char *envp[] = { NULL };

	command = args[0];
	if (access(command, X_OK) == -1)
	{
		error_msg = "Error: No such file or directory\n";
		write(STDOUT_FILENO, error_msg, _strlen(error_msg));
		return;
	}
	pid  = fork();
	if (pid == 0)
	{
		if (execve(command, args, envp) == -1)
		{
			perror("ERROR:");
			exit(EXIT_FAILURE);
		}
	}
	else if (pid < 0)
		perror("Error:");
	else
	{
		int status;
		waitpid(pid, &status, 0);
	}
}
