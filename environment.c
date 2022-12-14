#include "zlshell.h"

/**
 * _env - Set  linked list for the environment
 * 
 * Return: head of the linked list
 */
path_t *_env(void)
{
	path_t *head;
	path_t *house;
	int count = 0;

	/* Linked list*/
	house = malloc(sizeof(path_t));
	if (!house)
	{
		free(house);
		return (NULL);
	}
	/* Pointer to the beginning of list */
	head = house;
	/* Environ makes user environment */
	while (environ[count])
	{
		/* Duplicate variable into list */
		house->ptr = _strdup(environ[count]);
		if (environ[count + 1] != NULL)
		{
			house->next = malloc(sizeof(path_t));
			house = house->next;
		}
		count++;
	}
	house->next = NULL;
	return (head);
}

/**
 * env_find - searches for a match in the enviornment list
 * 
 * @var: argument passed in
 * 
 * Return: pointer to matched variable
*/
char *env_find(char *var)
{
	char *same, *store;
	path_t *node;
	unsigned int count;

	same = NULL;
	node = environment; /*runs environment list (man env)*/

	while (node)
	{
		count = 0;
	/*while there are arguments*/
		while (var[count])
		{
			if (var[count] != node->ptr[count])
				break;
			if (var[count + 1] == '\0' && node->ptr[count + 1] == '=')
			same = node->ptr;
			count++;
		}
		/** once we find a match exit loop*/
		if (same)
			break;
		node = node->next;
	}
	store = malloc(sizeof(char) * (_strlen(same) + 1));
	if (!store)
		/*free (store);*/
		return (NULL);
	_strcpy(store, same);
	return (store);
}
/**
 * env_match - finds the matching enviornment with the argument passed
 * 
 * @input: argument passed
 * 
 * Return: 0 on success, -1 if no match
*/
int env_match(char *input)
{
	path_t *peter;
	int count = 0, count_two = 0;

	/*setting environment*/
	peter = environment; 
	while (peter)
	{
		count = 0;
		while (input[count] == peter->ptr[count])
		{
			count++;
			if (input[count + 1] == '\0' && (peter->ptr)[count + 1] == '=')
				return (count_two);
		}
		count_two++;
		peter = peter->next;
		if (peter == NULL)
			return (-1);
	}
	return (count_two);
}
