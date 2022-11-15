#include <stdio.h>
#include <unistd.h>
#include <stdio.h>

int execute(char *argv[])
{
    *argv[] = {"/bin/ls", "-l", "/usr/", NULL};
    pid_t child_status = 0;

    printf("Before execve\n");
    switch(child_status = fork())
    {
        case -1:
            perror("Error.");
            exit(99);
        case 0:
            if (execve(argv[0], argv, NULL) == -1)
                perror("ERROR\n");
                exit(99);
            break;
        default:
            sleep(3);
            break;
    }
    printf("After execve\n");
    return (0);
}
