#include "main.h"
/**
  * main - Used to get parent process identification.
  * Return: int.
  */

int main(void)
{
	pid_t my_pid;

	my_pid = getppid();
	printf("%u\n", my_pid);
	return (0);
}
