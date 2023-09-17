#include "main.h"

/**
 * _cmd_check - A function used to check shell commands before they are run.
 * @ter_str: the string to be printed at the terminal.
 * @args: modified argumants passed to the program.
 * @av: unmodified arguments passed to the program.
 * @env: the OS environment variables.
 *
 * Return: void.
 */
void _cmd_check(char **args, char **av, char ***envi, int **status, char *lineptr, int **semi_seen, env_t **env)
{
	long number, len = 0;
	char *str, *lineptr2 = NULL, **args2, *oldpwd;
	ssize_t arr_size2 = 1, *_arr_size2 = &arr_size2;
	struct stat st;
	int count = 0;

	if ((args[0][0] == 'e') && (args[0][1] == 'x') && (args[0][2] == 'i') && (args[0][3] == 't') && (args[0][4] == '\0'))
	{
		_free_env(*envi);
		_free_env_nodes(env);
		free(lineptr);
		if ((args[1] != NULL) && ((args[1][0] < '0') || args[1][0] > '9'))
		{
			dprintf(STDERR_FILENO, "%s: %d: exit: Illegal number: %s\n",
		av[0], 1, args[1]);
		/*	free(lineptr);*/
			_free(args);
			exit(2);
		}
		else if ((args[1] != NULL) && (atoi(args[1]) < 0))
		{
			dprintf(STDERR_FILENO, "%s: %d: exit: Illegal number: %d\n",
		av[0], 1, atoi(args[1]));
/*			free(lineptr);*/
			_free(args);
			exit(2);
		}
		else if ((args[1] != NULL) && ((args[1][0] >= '0') || args[1][0] <= '9'))
		{
			number = strtol(args[1], &str, 10);
/*			free(lineptr);*/
			_free(args);
			exit(number);
		}
		if (**status == 512)
		{
			**status = 0;
/*			free(lineptr);*/
			_free(args);
			exit(2);
		}
		else
		{
/*			free(lineptr);*/
			_free(args);
			exit(0);
		}
	}
	else if ((args[0][0] == '/') && (args[0][1] == 'b') && (args[0][2] == 'i') && (args[0][3] == 'n') && (args[0][4] == '/') && (args[0][5] == 'e') && (args[0][6] == 'n') && (args[0][7] == 'v') && (args[0][8] == '\0'))
	{
		_print_env2(*envi);
		if (isatty(STDIN_FILENO) == 1)
			_p_ter_str(env);
	}
	else if ((args[0][0] == 's') && (args[0][1] == 'e') && (args[0][2] == 't') && (args[0][3] == 'e') && (args[0][4] == 'n') && (args[0][5] == 'v') && (args[0][6] == '\0'))
	{
	        if ((args[1] == NULL) || (args[2] == NULL)|| (args[3] != NULL))
		{
			dprintf(STDERR_FILENO, "usage: setenv VARIABLE VALUE.\n");
			if (isatty(STDIN_FILENO) == 1)
				_p_ter_str(env);
		}
		else
		{
			if (_check_or_create_env_node(env, args) == 1)
			{
				/*_free_env(*envi);
				_setup_env(env, envi);*/
				if (isatty(STDIN_FILENO) == 1)
					_p_ter_str(env);
				_free_n_setup_envi(envi, env);
			}
			
		}
	}
	else if ((args[0][0] == 'u') && (args[0][1] == 'n') && (args[0][2] == 's') && (args[0][3] == 'e') && (args[0][4] == 't') && (args[0][5] == 'e') && (args[0][6] == 'n') && (args[0][7] == 'v') && (args[0][8] == '\0'))
	{
		if ((args[1] == NULL) || (args[2] != NULL))
		{
			dprintf(STDERR_FILENO, "usage: unsetenv VARIABLE.\n");
			if (isatty(STDIN_FILENO) == 1)
				_p_ter_str(env);
		}
		else
		{
			if (_unsetenv(env, args) == 0)
			{
			/*	_free_env(*envi);
				_setup_env(env, envi);*/
				if (isatty(STDIN_FILENO) == 1)
					_p_ter_str(env);
				_free_n_setup_envi(envi, env);
			}
		}
	}
	else if ((args[0][0] == 'c') && (args[0][1] == 'd') && (args[0][2] == '\0'))
	{
		count = 0;
		while (args[count] != NULL)
			count++;
		if (count > 2)
		{
			dprintf(STDERR_FILENO, "usage: cd directory.\n");
			if (isatty(STDIN_FILENO) == 1)
				_p_ter_str(env);
		}
		else
		{
			if ((((args[1] != NULL) && (access(args[1], F_OK|R_OK) == 0)) && ((args[1] != NULL) && (stat(args[1], &st) == 0))) || ((args[1] != NULL) && (strcmp(args[1], "-") == 0)) || (args[1] == NULL))
			{
			/*	if ((S_ISDIR(st.st_mode)) || ((args[1] != NULL) && (strcmp(args[1], "-") == 0)) || (args[1] == NULL)) */
				if ((_getenv(env, "OLDPWD") != NULL) && (_getenv(env, "HOME") != NULL))
				{
					len = 0;
					len = len + strlen("setenv");
					len = len + strlen("PWD");
					if (args[1] == NULL)
					{
						len = len + strlen(_getenv(env, "HOME")) + 1;
						chdir(_getenv(env, "HOME"));
					}
					else if (strcmp(args[1], "-") == 0)
					{
						len = len + strlen(_getenv(env, "OLDPWD"));
						chdir(_getenv(env, "OLDPWD"));
						dprintf(STDOUT_FILENO, "%s\n", _getenv(env, "OLDPWD"));
					/*	oldpwd = malloc(sizeof(char) * (strlen(_getenv(env, "PWD")) + 1));
						if (oldpwd != NULL)
						{
							oldpwd[0] = '\0';
							strcat(oldpwd, _getenv(env, "PWD"));
						}*/
					}
					else
					{
						len = len + strlen(args[1]);
						chdir(args[1]);
					}
					oldpwd = malloc(sizeof(char) * (strlen(_getenv(env, "PWD")) + 1));
					if (oldpwd != NULL)
					{
						oldpwd[0] = '\0';
						strcat(oldpwd, _getenv(env, "PWD"));
					}
					lineptr2 = malloc(sizeof(char) * (len + 3));
					if (lineptr2 != NULL)
					{
						lineptr2[0] = '\0';
						strcat(lineptr2, "setenv");
						strcat(lineptr2, " ");
						strcat(lineptr2, "PWD");
						strcat(lineptr2, " ");
						if (args[1] == NULL)
							strcat(lineptr2, _getenv(env, "HOME"));
						else if (strcmp(args[1], "-") == 0)
							strcat(lineptr2, _getenv(env, "OLDPWD"));
						else
							strcat(lineptr2, args[1]);
						lineptr2[(len + 2)] = '\0';
					/*	printf("lineptr2: %s\n", lineptr2);*/
						args2 = _strtok(lineptr2, &_arr_size2);
						if (args != NULL)
						{
						/*	printf("args2 0: %s\n", args2[0]);
							printf("args2 1: %s\n", args2[1]);
							printf("args2 2: %s\n", args2[2]);*/
							if (_check_or_create_env_node(env, args2) == 1)
								_free_n_setup_envi(envi, env);
						}
						free(lineptr2);
						_free(args2);
					}
				/*	if ((args[1] != NULL) && (strcmp(args[1], "-") == 0)) */
					len = 0;
					arr_size2 = 1;
					len = len + strlen("setenv");
					len = len + strlen("OLDPWD");
					len = len + strlen(oldpwd);
					lineptr2 = malloc(sizeof(char) * (len + 3));
					if (lineptr2 != NULL)
					{
						lineptr2[0] = '\0';
						strcat(lineptr2, "setenv");
						strcat(lineptr2, " ");
						strcat(lineptr2, "OLDPWD");
						strcat(lineptr2, " ");
						strcat(lineptr2, oldpwd);
						lineptr2[(len + 2)] = '\0';
						args2 = _strtok(lineptr2, &_arr_size2);
						if (args2 != NULL)
							if (_check_or_create_env_node(env, args2) == 1)
								_free_n_setup_envi(envi, env);
						/*printf("oldpwd: %s\n", oldpwd);*/
						free(lineptr2);
						_free(args2);
						free(oldpwd);
					}
				}
				else
					if (args[1] != NULL)
						dprintf(STDOUT_FILENO, "%s\n", _getenv(env, "PWD"));
			/*	}
				else
					printf("not found 1\n");*/
			}
			else
				dprintf(STDERR_FILENO, "%s: 1: cd: can't cd to %s\n", av[0], args[1]);
			if (isatty(STDIN_FILENO) == 1)
				_p_ter_str(env);
		}
	}
	else
		_fork(args, av, *envi, status, lineptr, semi_seen, env);
}
