#include "main.h"

/**
 * main - A program to describe strings and arguments to main
 *
 *Return: 0 Always (Success)
 */

int main(int argc, char *argv[])
{
	int i;

	for (i = 0; i < argc; i++)
		printf("argv[%d]: %s\n", i, argv[i]);
	exit(EXIT_SUCCESS);
}
