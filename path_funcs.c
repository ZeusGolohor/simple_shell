#include "zlshell.h"
/* Functions neede to create and handle the path */

/**
 * path_gen - Generate the path
 * 
 * Return: pointer to the head of the list
 */
path_t *path_gen(void)
{
	path_t *head;
	path_t *node;
	char *t_path, *token;

	t_path = NULL;
	/* Node in linked list */
	node = malloc(sizeof(path_t));
	if (!node)
		return (NULL);

	/* env_findpoints t variable list */
	t_path = env_find("PATH");
	if (!t_path)
	{
		free(node);
		return (NULL);
	}

	/* Splits the path into tokens */
	token = _strtok(t_path, "=:;");
	head = node;

	while (token)
	{
		if (token)
		node->ptr = _strdup(token);
		/* Replaces with NULL*/
		if (token)
		{
			/* Place the token in the linked list if it exists*/
			node->next = malloc(sizeof(path_t));
			if (!node->next)
			{
				pth_free(head);
				return (NULL);
			}
			node->next = NULL;
		}
		free(t_path);
	}
	return (head);
}