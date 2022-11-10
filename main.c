#include "main.h"

/**
 * main - printing a prompt
 *
 * @argc: counts the number of arguments
 * @argv: An array of arguments
 *
 * Return: 0
 */

int main(__attribute__((unused))int argc, __attribute__((unused))char **argv)
{
    char *prompt = "(ZLShell) $ ";

    /*To store the address f the buffer holding whatever was typed*/
    char *lineptr;
    /*To store the alloacted size in bytes*/
    size_t n = 0;

    /*Creating an infinite loop*/
    while (1)
    {
    printf("%s", prompt);
    /*Stdin is stream that represents the source we want the function to get the data from, standard input*/
    getline(&lineptr, &n, stdin);
    printf("%s\n", lineptr);

    free(lineptr); /*getline alloactes memory dynamically, so we have to free the memory*/
    }

    return (0);
}
