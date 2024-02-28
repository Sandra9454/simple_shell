#include "shell.h"

#define MAX_LINE 1024

/**
 * main - main function
 * Return: 0 on success
 */

int main(void)
{
	char command[MAX_LINE];
	char *argv[2];
	char prompt[] = "#cisfun$";

	argv[1] = NULL;

	while (1)
	{

	write(STDOUT_FILENO, prompt, sizeof(prompt) - 1);
	if (fgets(command, MAX_LINE, stdin) == NULL)
	{
		write(STDOUT_FILENO, "\n", 1);
		break;
	}

	if (command[strlen(command) - 1] == '\n')
	{
		command[strlen(command) - 1] = '\0';
	}

	argv[0] = command;

	if (fork() == 0)
	{
		if (execve(command, argv, NULL) == -1)
		{
			perror(command);
			exit(EXIT_FAILURE);
		}
		else
		{
			wait(NULL);
		}
	}

	}
	return (0);

}
