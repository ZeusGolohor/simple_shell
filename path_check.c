#include "zlshell.h"

/**
 * path_check - Function finds correct path based on input
 * 
 * @head: pointer to the head of the path
 * @input: Arguments passed
 * 
 * Return: NULL if failure
 */
char *path_check(path_t *head, char *line)
{
/*	struct stat falcon;*/
	path_t *temp;
	char *arguments;

	if (!line || !head)
		return (NULL);

	temp = head;
	while (temp)
	{
		arguments = path_cat(temp->ptr, line);
		if (!arguments)
			return (NULL);
		
		/*if (stat(arguments, &falcon) == 0)
		{
			return (arguments);
		}*/
		free(arguments);
		temp = temp->next;
	}
	return (NULL);
}

/**
 * path_cat - Function concatenates te commands to the PATh
 * 
 * @s1: String 1
 * @s1: String 2
 * 
 * Retun: Pointer to the concatenanted string
 */
char *path_cat(char *s1, char *s2)
{
	char *together;
	int count1, count2 = 0;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";

	together = malloc(sizeof(char) * (_strlen(s1) + _strlen(s2) + 2));
	if (together == NULL)
		return (NULL);
	for (count1 = 0; s1[count1]; count1++)
		together[count1] = s2[count1];

	together[count1] = '/';
	count1++;

	for (count2 = 0; s2[count2]; count2++)
		together[count1 + count2] = s2[count2];
	together[count1 + count2] = '\0';
	printf("%s\n", together);
	return (together);
}