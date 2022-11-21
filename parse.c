#include "zlshell.h"

/**
 * word_count - Counts the words
 *
 * @str: string
 *
 * Return: number of input words
 */
int word_count(char *str)
{
	int i;
	int count = 1;
	int delim = ' ';

	if (!str)
		return (-1);

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == delim)
			count++;
	}
	return (count);
}

/**
 * parse - tokenizes the buffer
 *
 * @buffer: args to tokenize
 * @delim: delimeter
 *
 * Return: pointer to array of tokens
 */
char **parse(char *buffer, char *delim)
{
	char *tokens, *house;
	int count = word_count(buffer);
	int i = 0;
	char **words = malloc(sizeof(char *) * (count + 1));

	if (!words)
	{
		perror("Error\n");
		exit(99);
		
	}
	house = _strdup(buffer);
	if (!house)
	{
		perror("Error\n");
		return (NULL);
	}
	tokens = _strtok(house, delim);

	while (tokens)
	{
		words[i] = malloc(sizeof(char) * (_strlen(tokens) + 1));
		if (!words[i])
		{
			perror("Error");
			while (i >= 0)
			{
				free(words[i]);
				i--;
			}
			free(words);
			return (NULL);
		}
		_strcpy(words[i], tokens);
		i++;
		tokens = _strtok(NULL, delim);
	}
	words[i] = NULL;
	free(house);
	return (words);
}