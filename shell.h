#ifndef SHELL_H
#define SHELL_H

#define BUFFER_SIZE 1024
#define DELIMITERS " \t\r\n\a"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <signal.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/stat.h>

void loop(void);
char *read_line(void);
int execute(char **args);
char **split_line(char *line);

void _printenv(void);
void signal_handler(int sig);

int hsh_env(char **args);
int hsh_exit(char **args);
int hsh_help(char **args);
int hsh_cd(char **args);

#endif
