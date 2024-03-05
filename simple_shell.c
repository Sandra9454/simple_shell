#include "shell.h"

extern char **environ;

/**
 * get_cmd - Reads a command from standard input.
 * @lineptr: pointer to buffer to hold the read line.
 * Return: no. of chracters read, -1 on faliure.
 */

ssize_t get_cmd(char **lineptr)
{
	size_t bufsize = 0;

	write(STDOUT_FILENO, "#cisfun$ ", 9);
	return (getline(lineptr, &bufsize, stdin));
}

/**
 * trim_newline - removes the newline character from,
 * string if present.
 * @line: the string to be modified
 */

void trim_line(char *line)
{
	int len = strlen(line);

	if (len > 0 && line[len - 1] == '\n')
	{
		line[len - 1] = '\0'
	}
}


