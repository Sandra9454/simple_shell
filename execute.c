#include "shell.h"

#define MAX_ARGS 64
#define MAX_LINE 1024
/**
 * execute - execute a command
 * @line: command to be executed
 * Return: 0 on success
 */

void execute(char *line)
{

	char *argv[10];
	char *token;
	int i = 0;
	pid_t pid;

	token = strtok(line, " \n\t\r");
	while (token != NULL)
	{
		argv[i++] = token;
		token = strtok(NULL, " \n\t\r");
	}

	argv[1] = NULL;

	if (argv[0] == NULL)
	{
		return;
	}

	pid = fork();

	if (pid == 0)
	{
		if (execvp(argv[0], argv) == -1)
		{
			perror(argv[0]);
			exit(EXIT_FAILURE);
		}
	}
	else if (pid < 0)
	{
		perror("Erroe");
	}
	else
	{
		wait(NULL);
	}
}
