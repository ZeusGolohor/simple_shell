#include "zlshell.h"

/**
 * _strlen - Function that checks the lenght of a string
 *
 * @s: A character
 *
 * Return: The result of function
 */
int _strlen(char *s)
{
	int a = 0;

	for (; *s++;)
		a++;
	return (a);
}

/**
 * _puts - Functions prints a string
 *
 * @str: A pointer to the string to print
 *
 * Return: void
 */
void _puts(char *str)
{
	int x = 0;

	while (str[x])
	{
		_putchar(str[x]);
		x++;
	}
	_putchar('\n');
}

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _strncpy - Copies a string
 *
 * @dest: Destination of pointer string
 * @src: Source of pointer string
 * @n: Is an integer
 *
 * Return: 0 Always (Succes)
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i;

	for (i = 0; i < n && src[i] != '\0'; i++)
		dest[i] = src[i];

	for (; i < n; i++)
		dest[i] = '\0';

	return (dest);
}