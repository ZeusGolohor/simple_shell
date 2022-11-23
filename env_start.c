#include "zlshell.h"

/**
 * env_start - Creates a new environment variable from input
 * 
 * @str: input string
 * @value: Value of new variable
 * 
 * Return: void 
 */
void env_start(char *str, char *value)
{
	path_t *var, *copy, *node;
	char *val, *new_env;
	int val_len = 0, len = 0, counter = 0;

	if (!str || !value)
	{
		perror("Environment variable not passed");
		exit(1);
	}
	len = env_match(str);
	var = malloc(sizeof(path_t));
	if (!var)
		perror("error, error, error");
	val = _strcat(str, "=");
	val_len = _strlen(val);
	new_env = _realloc(val, val_len, (val_len + _strlen(value) + 1));
	_strncpy(new_env, value, val_len);
	copy = environment;
	node = environment;
	if (len >= 0)
	{
		while (counter != (len - 1))
		{
			node = node->next;
			copy = copy->next;
			counter++;
		}
		copy = copy->next;
		var->ptr = new_env;
		var->next = node->next->next;
		node->next = var;
		free(copy);
	}
	else 
	{
		while (node->next != NULL)
			node = node->next;
		var->ptr = new_env;
		node->next = var;
		var->next = NULL;
	}
	free(val);
}
