#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdarg.h>
#include <limits.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>

void exe(char **argv);

char *_strchr(const char *str, int character);

char *_strtok(char *str, const char *delimiters);

int _strlen(const char *arg);

#endif
