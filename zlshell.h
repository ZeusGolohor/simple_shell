#ifndef ZLSHELL_H
#define ZLSHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

extern char **environ;

/**
 * struct liststr - singly linked list
 * 
 * @num: the number field
 * @str: a string
 * @next: points to the next node
 */
typedef struct liststr
{
    int num;
    char str;
    struct liststr *next;
}list_t;

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
int execute_shell(char **args, char *snail);

/* Path functions */
path_t *path_gen(void);
char *path_check(path_t *head, char *input);
char *path_cat(char *s1, char *s2);

/* Built-in functions */
int isit_built(char **args, char *input);

/* Environment Functions */
path_t *_env(void);
char *env_find(char *var);
int env_match(char *input);

/* String tokenize Functions*/
char *_strtok(char str[], const char *delim);
int word_count(char *str);

/* Execution */

/* Functions that free */
void pth_free(path_t *head);
void env_free(path_t *head);

/* string_funcs.c */
int _strlen(char *s) //0x05
void _puts(char *str); //0x05
int _putchar(char c);
char *_strncpy(char *dest, char *src, int n)

/* string_help.c*/
char *_strdup(const char *s); //0x0B 
int _strcmp(char *s1, char *s2); //0x06
char *_strcat(char *dest, char *src); //0x06
char *_strcpy(char *dest, char *src); //0x05

/* mylists.c*/
list_t *add_nodeint(list_t **head, const int n); //0x13
list_t *add_nodeint_end(list_t **head, const int n); //0x13
size_t print_list(const list_t *h); //0x12
int delete_nodeint_at_index(list_t **head, unsigned int index); //0x13
void free_listint2(list_t **head); //0x13

/* mylists1.c*/
size_t list_len(const list_t *h); //0x12
char **list_to_strings(list_t *head); //new
size_t print_list_all(const list_t *h); //new
list_t *node_starts_with(list_t *node, char *prefix, char c); //new
list_t *get_nodeint_at_index(list_t *head, unsigned int index); //0x13




/* exits.c */
char *_strncpy(char *dest, char *src, int n); //0x06
char *_strncat(char *dest, char *src, int n); //0x06
char *_strchr(char *s, char c); //0x07

/* Variables */
path_t *the_path;
path_t *enviroment;
void errenous(char **args, char *cmd, int errno);
int line_count;
void sig_handler(int sig_handler);




char *_strchr(char *s, char c); 
int _strspn(char *s, char *accept);










#endif /* MAIN_H */