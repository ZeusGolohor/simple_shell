#include "zlshell.h"

/**
 * waru - Checks if the character is the delimeter (Who are you)
 * 
 * @z: Char being matched
 * @delim: input string
 * 
 * Return: 1 if the character matches the delimeter
 */
int waru(char z, const char *delim)
{
	while (*delim && delim)
	{
		if (z == *delim)
		{
			return (1);
		}
		++delim;
	}
	return (0);
}

/**
 * _strtok - Creates an array of tokens
 * 
 * @input: input string
 * @delim: delimeter " "
 * 
 * Return: pointer to head of list PATH
 */
char *_strtok(char *input, const char *delim)
{
	static char *w;
	static unsigned int v;
	char *tokens = NULL;
	int control = 0;

	if (input)
	{
		w = input;
		for (v = 0; w[v]; v++)
		{
			if (waru(w[v], delim))
				w[v] = '\0';
		}
	}
	
	if (w == NULL || *w == '\0')
		return (NULL);
	tokens = w;
	v = _strlen(w);
	if (w[v] == '\0' && _strlen(w) > 0)
		control = 1;
	w = w + _strlen(w) + control;
	printf("%s\n", tokens);
	return (tokens);
}