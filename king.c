#include "zlshell.h"

/**
 * king - Takes input from the shell
 *
 * @roar: The bloody shell
 *
 * Return: void
 */
void king(char *roar)
{
	 char *line;
	 char **args;
	 int status, i;

	 environment = _env();
	 the_path = path_gen();
	 line_count = 0;

	 /* Keeps loop running while shell is open*/
	 status = 1;
	 while(status)
	 {
		  signal(SIGINT, sig_handler);
		  line_count++;
		  /* Function to read a line */
		  line = read_line();
		  if (line[0] == '\n')
		  {
				free(line);
				continue;
		  }
		  /* Splits the line into arguments*/
		  args = parse(line, "\n");
		  if (isit_built(args, line) == 1)
				/* Determines when to exit */
				status = execute_shell(args, roar);

		  i = 0;
		  while (args[i] != NULL)
		  {
				if (args[i])
					 free(args[i]);
				i++;
		  }
		  if (line)
				free(line);
		  if (args)
				free(args);
	 }
	 pth_free(the_path);
	 pth_free(environment);
}