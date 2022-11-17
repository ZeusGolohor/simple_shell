#include "zlshell.h"

/**
 * add_nodeint - Function adds a new node at the beginning of list
 *
 * @head: A pointer to head of the list
 * @n: The integer for the new node to contain
 *
 * Return: the address of the new element: or "NULL" if failure
 */
list_t *add_nodeint(list_t **head, const int n)
{
	list_t *new;

	new = malloc(sizeof(list_t));
	if (new == NULL)
		return (NULL);

	new->n = n;
	new->next = *head;

	*head = new;

	return (new);
}

/**
 * add_nodeint_end - Function that adds a new node at the end of a list
 *
 * @head: A pointer to the head of the list
 * @n: The integer for the new node to contain
 *
 * Return: the address of the new element: or "NULL" if failure
 */
list_t *add_nodeint_end(list_t **head, const int n)
{
	list_t *new, *last;

	new = malloc(sizeof(list_t));
	if (new == NULL)
		return (NULL);

	new->n = n;
	new->next = NULL;

	if (*head == NULL)
		*head = new;

	else
	{
		last = *head;
		while (last->next != NULL)
			last = last->next;
		last->next = new;
	}
	return (*head);
}

/**
 * print_list - Function prints all the elements in a linked list
 *
 * @h: pointer to first node in linked list
 *
 * Return: the number of nodes
 */
size_t print_list(const list_t *h)
{
	size_t n = 0;

	while (h)
	{
		if (h->str == NULL)
			printf("[0] (nil)\n");

		else
			printf("[%d] %s\n", h->len, h->str);

		n++;
		h = h->next;
	}
	return (n);
}

/**
 * delete_nodeint_at_index - Function deletes a node at index, of a linked list
 *
 * @head: double pointer to the head of the list
 * @index: Delete a node at this index, count starts at 0
 *
 * Return: 1 (Success): or -1 (Failure)
 */
int delete_nodeint_at_index(list_t **head, unsigned int index)
{
	listint_t *current;
	listint_t *hold;
	unsigned int i;

	i = 0;
	current = *head;
	if (*head == NULL)
		return (-1);

	while (i < index)
	{
		i++;
		hold = current;
		if (current->next)
			current = current->next;
		else
			return (-1);
	}

	if (index == 0)
		*head = current->next;
	else if (current->next)
		hold->next = current->next;
	else
		hold->next = NULL;

	free(current);
	return (1);
}

/**
 * free_listint2 - Function frees a linked list & sets the head to "NULL"
 *
 * @head: a pointer that points to the head of a list
 *
 * Return: void
 */
void free_listint2(list_t **head)
{
	listint_t *tmp;

	if (head == NULL)
		return;

	while (*head)
	{
		tmp = (*head)->next;
		free(*head);
		*head = tmp;
	}
	head = NULL;
}