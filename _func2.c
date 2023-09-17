#include "main.h"

int _setenv(env_t ***env, char **args)
{
	env_t *temp;
	int seen = 0;
	env_t *new_node;
	char *separator = "=";

/*	if ((args == NULL) || (*args == NULL))
		exit(0);
	if ((args[1] == NULL) || (args[2] == NULL))
	{
		dprintf(STDERR_FILENO, "usage: setenv VARIABLE VALUE\n");
		dprintf(STDOUT_FILENO, "($) ");
		return (-1);
	}*/
	if (**env != NULL)
		temp = **env;
	while (temp->next != NULL)
	{
	/*	printf("%s\n", args[1]);*/
		if ((args[1] != NULL) && (strcmp(temp->var, args[1]) == 0))
		{
			seen = 1;
		/*	printf("%s\n", temp->var_n_val);*/
			printf("seen\n");
		}
		temp = temp->next;
	}
/*	printf("%s\n", args[1]);*/
	if ((temp->next == NULL) && (seen == 0))
	{
			new_node = malloc(sizeof(env_t));
			if (new_node == NULL)
				return (-1);
			/*new_node->var = malloc(sizeof(char) * (strlen(args[1] + 1)));*/
			new_node->var = malloc(sizeof(char) * (strlen(args[1]) + 1));
			new_node->val = malloc(sizeof(char) * (strlen(args[2]) + 1));
			new_node->var_n_val = malloc(sizeof(char) * (strlen(args[1]) + strlen(separator) + strlen(args[2]) + 1));
		if ((new_node->var == NULL) || (new_node->val == NULL) || (new_node->var_n_val == NULL))
			return (-1);
		new_node->var[0] = '\0';
		new_node->val[0] = '\0';
		new_node->var_n_val[0] = '\0';
		strcat(new_node->var_n_val, args[1]);
		strcat(new_node->var_n_val, separator);
		strcat(new_node->var_n_val, args[2]);
		new_node->next = NULL;
		_add_env(*env, new_node);
/*		_free_env_b_head(*env, envi, av, status);*/
	/*	_print_env(*env);
		_setup_env(*env, envi); 
		_print_env2(*envi);*/
	}	
	return (0);
}

int _print_env2(char **env)
{
	int i;

	if (*env == NULL)
		return (-1);
	i = 0;
	while (env[i] != NULL)
	{
		dprintf(STDOUT_FILENO, "%s\n", env[i]);
		++i;
	}
	return (0);
}

env_t *_create_env_node(char **args)
{
	env_t *new_env_node;
	char *variable = args[1], *value = args[2], *separator = "=";

	new_env_node = malloc(sizeof(env_t));
	if (new_env_node == NULL)
		return (NULL);
	new_env_node->var = malloc(sizeof(char) * (strlen(variable) + 1));
	new_env_node->val = malloc(sizeof(char) * (strlen(value) + 1));
	new_env_node->var_n_val = malloc(sizeof(char) * (strlen(variable) + strlen(separator) + strlen(value) + 1));
	if ((new_env_node->var == NULL) || (new_env_node->val == NULL) || (new_env_node->var_n_val == NULL))
		return (NULL);
	new_env_node->var[0] = '\0';
	new_env_node->val[0] = '\0';
	new_env_node->var_n_val[0] = '\0';
	strcat(new_env_node->var, variable);
	strcat(new_env_node->val, value);
	strcat(new_env_node->var_n_val,new_env_node->var);
	strcat(new_env_node->var_n_val,separator);
	strcat(new_env_node->var_n_val,new_env_node->val);
	new_env_node->next = NULL;
	return (new_env_node);	
}

int _unsetenv(env_t **env, char **args)
{
	env_t *head, *mem_to_free;

	if (env == NULL)
		return (-1);
	head = *env;
	while (head != NULL)
	{
		if (head->next == NULL)
		{
			dprintf(STDERR_FILENO, "env variable: \"%s\" not found.\n", args[1]);
			break;
		}
		else if (strcmp(head->next->var, args[1]) == 0)
		{
			mem_to_free = head->next;
			if (head->next->next != NULL)
				head->next = head->next->next;
			else
				head->next = NULL;
/*			free(mem_to_free->var);
			free(mem_to_free->val);
			free(mem_to_free->var_n_val);
			free(mem_to_free);*/
			if (_free_single_env_node(mem_to_free) == -1)
				return (-1);
			break;
		}
		else if (strcmp(head->var, args[1]) == 0)
		{
			mem_to_free = head;
			*env = head->next;
			/*free(mem_to_free->var);
			free(mem_to_free->val);
			free(mem_to_free->var_n_val);
			free(mem_to_free);*/
			if (_free_single_env_node(mem_to_free) == -1)
				return (-1);
			break;
		}
		head = head->next;
	}
	return (0);
}

int _free_single_env_node(env_t *mem_to_free)
{
	if (mem_to_free == NULL)
		return (-1);

	free(mem_to_free->var);
	free(mem_to_free->val);
	free(mem_to_free->var_n_val);
	free(mem_to_free);
	return (0);
}
