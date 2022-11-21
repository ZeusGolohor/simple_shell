#include "zlshell.h"

/**
 * shell_exit - exit current process
 * 
 * @args: arguments
 * @input: input
 * 
 * Return: void
 */
void shell_exit(char **args, char *input)
{
	unsigned int l = 0;

	if (input)
		free(input);
	if (args)
	{
		while (args[1 ])
		{
			if(args[l])
				free(args[l]);
			l++;
		}
		free(args);
	}
	pth_free(the_path);
	pth_free(environment);
	exit(0);
}

/**
 * print_environment - Prints the environment
 * 
 * Return: void
 */
void print_environment(void)
{
	path_t *node;

	node = environment;
	while (node)
	{
		write(1, node->ptr, _strlen(node->ptr));
		write(1, "\n", 1);
		node = node->next;
	}
}