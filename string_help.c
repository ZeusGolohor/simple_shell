#include "zlshell.h"

/**
 * char *_strdup - Returns pointer to newly allocated space in memory
 * also ontains a copy of the string as a parameter
 *
 * @str: A pointer string
 * Return: copy of "str": or "NULL" if "str" = "NULL":
 * or "NULL" if insufficient memory
 */
char *_strdup(char *str)
{
	char *x = NULL;
	int count;

	if (str == NULL)
	{
		return (NULL);
	}

	x = malloc(sizeof(char) * (_strlen(str) + 1));
	
	for (count = 0; str[count] != '\0'; count++)
	{
		x[count] = str[count];
	}
	x[count] = '\0';
	return (x);
}

/**
 * _strcmp - Function compares two strings.
 *
 * @s1: Comparing variable
 * @s2: Comparing variable
 *
 * Return: 0 if strings the same; negative or positive if not the same
 */
int _strcmp(char *st1, char *st2)
{
	while (*st1 != '\0' && *st2 != '\0' && (*st1 == *st2))
	{
		st1++;
		st2++;
	}

	if (*st1 == '\0' && *st2 == '\0')
		return (0);
	else
		return ((int)(*st1 - *st2));
}


/**
 * _strcat - Concatenate two strings
 *
 * @dest: Destination string
 * @src: Soruce string
 *
 * Return: 0 Always (Success)
 */
char *_strcat(char *dest, char *src)
{
	char *string = NULL;
	int ct1 = 0, ct2 = 0, st1 = 0, st2 = 0;

	while (dest[st1])
	{
		st1++;
	}
	while (src[st2])
	{
		st2++;
	}

	string = malloc(sizeof(st1 + st2 + 2));

	if (!string)
		free(string);
	for (ct1 = 0 ; dest[ct1] != '\0' ; ct1++)
	{
		string[ct1] = dest[ct1];
	}

	for (ct2 = 0 ; src[ct2] != '\0' ; ct2++)
	{
		string[ct1] = src[ct2];
		ct1++;
	}
	string[ct1] = '\0';
	return (string);
}

/**
 * *_strcpy -  function that copies the string pointed to by src,
 * including the terminating null byte (\0),
 * to the buffer pointed to by dest
 *
 * @dest: destination char
 * @src: source char
 *
 * Return: The pointer to dest
 */
char *_strcpy(char *dest, char *src)
{
	int x;

	for (x = 0; src[x] != '\0'; x++)
	{
		dest[x] = src[x];
	}
	dest[x] = '\0';
	return (dest);
}

/**
 * _strcpy_src - copies a string at specific index
 * @dest: destination
 * @src: source (index)
 * @n: legnth of destination
 * Return: string copied
*/
char *_strcpy_src(char *dest, char *src, int n)
{
	int ct;

	for (ct = 0 ; src[ct] != '\0' ; ct++, n++)
		dest[ct] = src[n];
	dest[ct] = '\0';
	return (dest);
}
