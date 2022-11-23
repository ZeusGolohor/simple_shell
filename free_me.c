#include "zlshell.h"

/**
 * pth_free - Function frees te linked list associated with the PATH
 * 
 * @head: Pointer to the head of the list
 * 
 * Return: void
 */
void pth_free(path_t *head)
{
    if (head == NULL)
        return;
    if (head->next != NULL)
        pth_free(head->next);
    free(head->ptr);
    free(head);
}

/**
 * env_free - Function frees the linked list associated with th environment
 * 
 * @head: Pointer to the head of linked list
 * 
 * Return: void
 */
void env_free(path_t *head)
{
    if (head == NULL)
        return;
    if (head->next != NULL)
        pth_free(head->next);
    free(head);
}
