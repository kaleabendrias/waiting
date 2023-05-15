#include "main.h"

/**
 * exe - executes argument
 * @args: argumnets
 * Return: none
 */

extern char **environ;

void exe(char **args)
{
	char *command, *actual_command, *error_msg, **env, *env_line;
	size_t env_len;
	pid_t pid;
	char *envp[] = { NULL };

	command = args[0];
	if (_strcmp(command, "exit") == 0)
	{
		free(command);
		exit(EXIT_SUCCESS);
	}
	if (_strcmp(command, "env") == 0)
	{
		env = environ;
		while (*env != NULL)
		{
			env_line = *env;
			env_len = _strlen(env_line);
			write(STDOUT_FILENO, env_line, env_len);
			write(STDOUT_FILENO, "\n", 1);
			env++;
		}
		return;
	}
	actual_command = get_loc(command);
	if (!actual_command)
	{
		error_msg = "Error: Command not found\n";
		write(STDOUT_FILENO, error_msg, _strlen(error_msg));
		return;
	}
	if (access(actual_command, X_OK) == -1)
	{
		free(actual_command);
		error_msg = "Error: No such file or directory\n";
		write(STDOUT_FILENO, error_msg, _strlen(error_msg));
		return;
	}
	pid = fork();
	if (pid == 0)
	{
		if (execve(actual_command, args, envp) == -1)
		{
			perror("ERROR:");
			free(command);
			free(actual_command);
			exit(EXIT_FAILURE);
		}
	}
	else if (pid < 0)
	{
		perror("Error:");
	}
	else
	{
		int status;

		waitpid(pid, &status, 0);
	}
	free(actual_command);
}
