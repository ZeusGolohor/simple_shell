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
	char *x;
	int strlen;
	int count;

	if (str == NULL)
	{
		return (NULL);
	}
	for (strlen = 0; str[strlen] != '\0'; strlen++)
	{

	}
	x = malloc(strlen * sizeof(char) + 1);
	if (x == NULL)
	{
		return (NULL);
	}
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
int _strcmp(char *s1, char *s2)
{
	int i;

	for (i = 0; s1[i] != '\0' || s2[i] != '\0'; i++)
	{
		if (s1[i] != s2[i])

			return (s1[i] - s2[i]);
	}
	return (0);
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
	int len1;
	int len2;
	int i;

	len1 = strlen(dest);
	len2 = strlen(src);
	for (i = 0; i <= len2; i++)
	{
		dest[len1 + i] = src[i];
	}
	return (dest);
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