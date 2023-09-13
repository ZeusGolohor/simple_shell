#include "main.h"

void _free(char **args)
{
	ssize_t i = 0;

	while (args[i] != NULL)
	{
		free(args[i]);
		++i;
	}
	free(args);
}

int _free_env_nodes(env_t **_env)
{
	env_t *temp, *free_node;

	if (*_env == NULL)
		return (-1);
	temp = *_env;
	while (temp != NULL)
	{
		free_node = temp;
		temp = free_node->next;
		free(free_node->var_n_val);
		free(free_node->var);
		free(free_node->val);
		free(free_node);
	}
	return (0);
}

int _free_env(char **envi)
{
	int i = 0;

	if (*envi == NULL)
		return (-1);
	while (envi[i] != NULL)
	{
		free(envi[i]);
		++i;
	}
	free(envi);
	return (0);
}

int _free_env_b_head(char ***envi)
{
	int i;
	
	if ((*envi == NULL) || (**envi == NULL))
		return (-1);
	i = 0;
	while ((*envi)[i] != NULL)
	{
		free((*envi)[i]);
		++i;
	}
/*	*envi = temp2;
         _setup_env(env, envi);
	_print_env2(*envi);*/
/*	printf("\nprinting new env\n");
	_print_env2(temp2);
	_shell(0, av, temp2, status, env);*/
/*	 _print_env2(*envi);*/
	return (0);
}
