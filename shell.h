#ifndef SHELL_H
#define SHELL_H

#define MAX_ARGS 64
#define BUFFER_SIZE 1024
#define DELIMITERS " \t\r\n\a"
#define _GNU_SOURCE

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

ssize_t get_cmd(char **lineptr);
void trim_newline(char *line);
void execute_cmd(char *cmd);
int main(void);
void parse_command(char *line, char **cmd, char ***args);
int handle_builtin(char *cmd);
void print_error(char *cmd);
char *get_env_var(char *name);

#endif
