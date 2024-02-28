#include "shell.h"
/**
 * main - amin entry point
 * @argc: argument count
 * @argv: argument vector
 * Return: always 0 on success.
 */

int main(int argc, char **argv)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;
	char *prompt = "$ ";

	(void)argc;
	(void)argv;

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, prompt, strlen(prompt));

	while ((nread = getline(&line, &len, stdin)) != -1)
	{
		execute(line);
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, prompt, strlen(prompt));
	}

	free(line);
	exit(EXIT_SUCCESS);
}
