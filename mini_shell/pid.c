#include <stdio.h.>
#include <unistd.h>

/**
 * main - Calls the getpid & getppid functions
 *
 * Return: 0 Always (Success)
 */
int main(void)
{
	pid_t my_pid;

	my_pid = getpid();
	printf("%u\n", my_pid);
	return (0);
}