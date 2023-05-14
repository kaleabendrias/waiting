#include "main.h"

/**
 * exe - executes the commands
 * @args: arguments
 * Return: none
 */
void exe(char **args)
{
    char *command, *actual_command;
    char *error_msg;
    pid_t pid;
    char *envp[] = { NULL };

    command = args[0];

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
