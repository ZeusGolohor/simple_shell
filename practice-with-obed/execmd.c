#include "main.h"

void execmd(char **argv)
{
    char *command = NULL;

    if (argv)
    {
	    /* Get the command*/
	    command = argv[0];
	    
	    /* Execute the command with execve */ 
	    if (execve(command, argv, NULL) == -1)
	    {
		    perror("Error:");
	    }
    }
}

//We are trying it  from git bash VS terminal
//This is pretty cool ngl
//I know right
//vim is the problem
