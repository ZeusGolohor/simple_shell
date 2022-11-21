#include "zlshell.h"

/**
 * read_line - Interperts the input
 *
 * Return: NULL
 */
char *read_line(void)
{
	char *line = NULL;
	/* Will change according to input */
	size_t bufsize = 0;

	write(1, "$ ", 2);
	if (getline(&line, &bufsize, stdin) <= 0)
	{
		if (isatty(STDIN_FILENO) == 1)
			write(STDOUT_FILENO, "\n", 1);
		shell_exit(NULL, line);
	}
	return (line);
}