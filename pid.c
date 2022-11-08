#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

/**
 * main - Calls the getpid & getppid functions
 *
 * Return: 0 Always (Success)
 */
int main(void)
{
	printf("Current Procces: %d\n Parent Process: %d\n", getpid(), getppid());

	return (0);
}
