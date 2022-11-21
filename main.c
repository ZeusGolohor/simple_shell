/**#include "zlshell.h"
 * main - shell replica
 *
 * @argc: number of arguments passed
 * @argv: array of arguments to be executed
 *
 * Return: 0 Always (Success)
 *
int main(int argc, char **argv)
{
	 (void)argc;

	 argv[0];

	 return (0);
} */

#include "zlshell.h"

/**
 * main - printing a prompt
 *
 * @argc: counts the number of arguments
 * @argv: An array of arguments
 *
 * Return: 0
 */

int main(int argc, char **argv)
{
	char *prompt = "(ZLShell) $ ";

	/*To store the address of the buffer holding whatever was typed*/
	char *lineptr = NULL;
	/*To hold the copy of the string to be passed to strtok*/
	char *lineptr_copy = NULL;
	/*To store the alloacted size in bytes*/
	size_t n = 0;
	/*Variable that holds the return value of the getline function*/
	ssize_t nchars_read;
	/*To hold the delimiters, considering an empty sspace and the \n as the possible delimiters*/
	const char *delim = "\n";
	/*To serve as the counter */
	int num_tokens = 0;
	/*To store the token generated*/
	char *token;
	int i;

	/*Declaring void variables*/
	(void)argc;

	/*Creating an infinite loop*/
	while (1)
	{
		printf("%s", prompt);
		/*Stdin is stream that represents the source we want the function to get the data from, standard input*/
		nchars_read = getline(&lineptr, &n, stdin);

		/*Check if the getline function failed or reached EOF or user use C^ + D*/
		if (nchars_read == -1)
		{
			printf("Exiting shell....\n");
			return (-1);
		}

		/* Allocate space for a copy of the lineptr*/
		lineptr_copy = malloc(sizeof(char) * nchars_read);
		if (lineptr_copy == NULL)
		{
			perror("tsh: memory allocation error");
			return (-1);
		}		

		/* Copy lineptr to lineptr_copy*/
		strcpy(lineptr_copy, lineptr);

		/***** Split the string (lineptr) into an array of words *****/
		/* Calculate the total number of tokens */
		token = strtok(lineptr, delim);

		/* Determine how may  tokens are there*/
		while (token != NULL)
		{
			num_tokens++;
			token = strtok(NULL, delim);
		}			
		num_tokens++;

		/* Allocate space to  hold the array of strings */
		argv = malloc(sizeof(char *) * num_tokens);

		/* Alloacte each token in the argv array*/
		token = strtok(lineptr_copy, delim);

		for (i = 0; token != NULL; i++)
		{
			argv[i] = malloc(sizeof(char) * strlen(token));
			strcpy(argv[i], token);

			token = strtok(NULL, delim);
		}
		argv[i] = NULL;

		/* Execute the command */
		execmd(argv);
	}


 /*getline alloactes memory dynamically, so we have to free the memory*/
	free(lineptr);
	free(lineptr_copy);
	
	
	return (0);
}