#include "shell.h"

/**
 * get_cmd - reads a command from standard input
 * @lineptr: pointer to the buffer to hold readline.
 * Return: number of characters read, incl.delimiter
 * reurn -1 on failure.
 */

ssize_t get_cmd(char **lineptr)
{
	size_t bufsize = 0;

	write(STDOUT_FILENO, "#cisfun$ ", 9);
		return (getline(lineptr, &bufsize, stdin));
}

/**
 * trim_newline - removes newline character from string.
 * @line: string to be modified.
 */

void trim_newline(char *line)
{
	int len = strlen(line);

	if (len > 0 && line[len - 1] == '\n')
	{
		line[len - 1] = '\0';
	}
}

/**
 * execute_cmd - execute a command using execve.
 * @cmd: the command to execute.
 */

void execute_cmd(char *cmd)
{
	pid_t pid;
	int status;
	char *argv[2];

	pid = fork();
	if (pid == -1)
	{
		perror("Error");
	}
	else if (pid == 0)
	{
		if (execve(cmd, argv, environ) == -1)
		{
			perror(cmd);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		do {
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
}

/**
 * main - entry point for simple shell.
 * Return: 0 on success.
 */

int main(void)
{
	char *line = NULL;
	ssize_t nread;

	while (1)
	{
		nread = get_cmd(&line);
		if (nread == -1)
		{
			if (feof(stdin))
				{
				write(STDOUT_FILENO, "\n", 1);
				free(line);
				exit(EXIT_SUCCESS);
				}
			else
			{
				perror("get_cmd");
				free(line);
				continue;
			}
		}
		trim_newline(line);
		execute_cmd(line);
	}
	free(line);
	return (0);
}