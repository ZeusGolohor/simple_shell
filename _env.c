#include "main.h"

int _setup_env_nodes(env_t **_env, char **envi_src)
{
	ssize_t i = 0, z, x;
	char value[9999], variable[9999], separator[] = "=";
	env_t *new_env_node;

	value[0] = '\0';
	variable[0] = '\0';
	while (envi_src[i] != NULL)
	{
		new_env_node = malloc(sizeof(env_t));
		if (new_env_node == NULL)
			return (-1);
		z = 0;
		value[0] = '\0';
		variable[0] = '\0';
		while (envi_src[i][z] != '=')
		{
			variable[z] = envi_src[i][z];
			++z;
		}
		variable[z] = '\0';
		++z;
		x = 0;
		while (envi_src[i][z] != '\0')
		{
			value[x] = envi_src[i][z];
			++x;
			++z;
		}
		value[x] = '\0';
		new_env_node->var = malloc(sizeof(char) * (strlen(variable) + 1));
		new_env_node->val = malloc(sizeof(char) * (strlen(value) + 1));
		new_env_node->var_n_val = malloc(sizeof(char) * (strlen(variable) + strlen(separator) + strlen(value) + 1));
		if ((new_env_node->var == NULL) || (new_env_node->val == NULL) || (new_env_node->var_n_val == NULL))
			return (-1);
		new_env_node->var[0] = '\0';
		new_env_node->val[0] = '\0';
		new_env_node->var_n_val[0] = '\0';
		strcat(new_env_node->var, variable);
		strcat(new_env_node->val, value);
		strcat(new_env_node->var_n_val,new_env_node->var);
		strcat(new_env_node->var_n_val,separator);
		strcat(new_env_node->var_n_val,new_env_node->val);
		new_env_node->next = NULL;
		_add_env(_env, new_env_node);
		++i;
	}

	return (0);
}

int _check_or_create_env_node(env_t **env, char **args)
{
	env_t *head, *new_env_node;
	int seen = 0;
	char *variable = args[1], *value = args[2], *separator = "=";

	if (env == NULL)
		return (-1);
	head = *env;
	while (head != NULL)
	{
		if (strcmp(head->var, args[1]) == 0)
		{
			seen = 1;
			free(head->val);
			free(head->var_n_val);
			head->val = malloc(sizeof(char) * (strlen(value) + 1));
			head->var_n_val =  malloc(sizeof(char) * (strlen(variable) + strlen(separator) + strlen(value) + 1));
			if ((head->val == NULL) || (head->var_n_val == NULL))
				return (-1);
			head->val[0] = '\0';
			head->var_n_val[0] = '\0';
			strcat(head->val, value);
			strcat(head->var_n_val, variable);
			strcat(head->var_n_val, separator);
			strcat(head->var_n_val, value);
			break;
		}
		if ((head->next == NULL) && (seen == 0))
		{
			seen = 1;
			new_env_node = _create_env_node(args);
			if (new_env_node == NULL)
				return (-1);
			_add_env(env, new_env_node);
			break;
		}
		head = head->next;
	}
	if (seen == 1)
		return (1);
	return (0);
}

int _add_env(env_t **_env, env_t *new_env_node)
{
	env_t *temp = *_env;

	if (*_env == NULL)
	{
		*_env = new_env_node;
	}
	else
	{
		temp = *_env;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new_env_node;
	}
	return (0);
}

int _print_env(env_t **_env)
{
/*	env_t *temp = *_env;*/
	env_t *temp;

	if (_env == NULL)
		return (-1);
	temp = *_env;
	while (temp != NULL)
	{
		printf("%s\n", temp->var_n_val);
		temp = temp->next;
	}
	return (0);
}

int _setup_env(env_t **_env, char ***_envi)
{
	env_t *temp;
	int i;
	ssize_t len;

	if (*_env == NULL)
		return (-1);

	temp = *_env;
	i = 0;
	while (temp != NULL)
	{
		++i;
	/*	printf("%s\n", temp->var_n_val);*/
		temp = temp->next;
	}
	*_envi = malloc(sizeof(char *) * (i + 1));
	if (*_envi == NULL)
		return (-1);
	temp = *_env;
	i = 0;
	while (temp != NULL)
	{
		len = 0;
		len = (strlen(temp->var_n_val) + 1);
		(*_envi)[i] = malloc(sizeof(char) * len);
		if ((*_envi)[i] == NULL)
			return (-1);
		(*_envi)[i][0] = '\0';
		strcat((*_envi)[i], temp->var_n_val);
	/*	strcpy((*_envi)[i], temp->var_n_val);*/
		++i;
		temp = temp->next;
	}
	(*_envi)[i] = NULL;
/*	i = 0;
	while((*_envi)[i] != NULL)
	{
		printf("%s\n", (*_envi)[i]);
		++i;
	}*/
	return (0);
}
