#ifndef ZLSHELL_H
#define ZLSHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "signal.h"

#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

extern char **environ;

/**
 * struct path - linked list of environment variables
 * 
 * @ptr: pointer to environment variables
 * @next: points to next node in linked list
 */
typedef struct path
{
    char *ptr;
    struct path *next;
}path_t;

/* Entry point */
int main(int argc, char **argv);

/* Input functions */
void king(char *roar);
char *read_line(void);
char **parse(char *buffer, char *delim);
int execute_shell(char **args, char *roar);

/* Path functions */
path_t *path_gen(void);
char *path_check(path_t *head, char *input);
char *path_cat(char *s1, char *s2);

/* Built-in functions */
int isit_built(char **args, char *input);
void shell_exit(char **args, char *input);
void print_environment(void);

/* Environment Functions */
path_t *_env(void);
char *env_find(char *var);
int env_match(char *input);
void env_start(char *str, char *value);

/* String tokenize Functions*/
int waru(char z, const char *delim);
char *_strtok(char str[], const char *delim);
int word_count(char *str);
char **parse(char *buffer, char *delim);

/* Execution */
int cmp_exec(char **args, char *roar);

/* Functions that free */
void pth_free(path_t *head);
void env_free(path_t *head);

/* string_funcs.c */
int _strlen(char *s);
void _puts(char *str);
int _putchar(char c);
char *_strncpy(char *dest, char *src, int n);

/* string_help.c*/
char *_strdup(char *str); 
int _strcmp(char *st1, char *st2);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
char *_strcpy_src(char *dest, char *src, int n);

/* atoi.c */
int _numlen(int n);
char *_atoi(int num);

/* Variables */
path_t *the_path;
path_t *environment;
void errenous(char **args, char *cmd, int errno);
int line_count;
void sig_handler(int sig_handler);
void *_realloc(void *ptr, unsigned int before, unsigned int after);
int find_match(const char *s1, char *s2);
char *_getenv(const char *name);
char *getpath(void);

#endif /* ZLSHELL_H */
