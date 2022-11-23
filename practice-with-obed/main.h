#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include <sys/types.h>

void execmd(char **argv);
char *get_location(char *command);

/* mylists.c*/
list_t *add_nodeint(list_t **head, const int n);
list_t *add_nodeint_end(list_t **head, const int n);
size_t print_list(const list_t *h);
int delete_nodeint_at_index(list_t **head, unsigned int index);
void free_listint2(list_t **head);

/* mylists1.c*/
size_t list_len(const list_t *h);
char **list_to_strings(list_t *head);
size_t print_list_all(const list_t *h);
list_t *node_starts_with(list_t *node, char *prefix, char c);
list_t *get_nodeint_at_index(list_t *head, unsigned int index);

#endif /* MAIN_H */
