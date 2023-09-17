#include "main.h"

void _ctrl_c_handler(__attribute__((unused)) int signal)
{
	if (isatty(STDIN_FILENO) == 1)
		dprintf(STDOUT_FILENO, "\n($) ");
}

void _p_ter_str(env_t **env)
{
	dprintf(STDOUT_FILENO, "%s@%s:%s($) ", _getenv(env, "USER"), _getenv(env, "NAME"), _getenv(env, "PWD"));
}

char *_getenv(env_t **env, char *variable)
{
	env_t *head;

	if (*env == NULL)
		return (NULL);
	head = *env;
	while (head != NULL)
	{
		if (strcmp(head->var, variable) == 0)
			return (head->val);
		head = head->next;
	}
	return NULL;
}

int _free_n_setup_envi(char ***envi, env_t **env)
{
	if ((*envi == NULL) || (*env == NULL))
		return (-1);


	_free_env(*envi);
	_setup_env(env, envi);
	return (0);
/*	if (isatty(STDIN_FILENO) == 1)
		_p_ter_str(env);*/
}
