#include "zlshell.h"

/**
 * main shell replica
 *
 * @argc: number of arguments passed
 * @argv: array of arguments to be executed
 *
 * Return: 0 Always (Success)
 */
int main(int argc, char **argv)
{
	 (void)argc;
	 
	 king(argv[0]);

	 return (0);
}