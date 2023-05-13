#include "main.h"

/**
 * get_loc - gets full path of command
 * @command: command
 * Return: Always
 */

char *get_loc(char *command)
{
    char *path, *path_copy, *path_token, *file_path;
    int command_len, directory_len;
    struct stat buffer;

    path = getenv("PATH");
    if (path)
    {
        path_copy = _strdup(path);
        command_len = _strlen(path);
        path_token = _strtok(path_copy, ":");
        while (path_token != NULL)
        {
            directory_len = _strlen(path_token);
            file_path = malloc(command_len + directory_len + 2);
            _strcpy(file_path, path_token);
            _strcat(file_path, "/");
            _strcat(file_path, command);
            _strcat(file_path, "\0");
            if (stat(file_path, &buffer) == 0)
            {
                free(path_copy);
                return file_path;
            }
            free(file_path);
            path_token = _strtok(NULL, ":");
        }
        if (stat(command, &buffer) == 0)
        {
            free(path_copy);
            return command;
        }
        free(path_copy);
    }
    return NULL;
}
