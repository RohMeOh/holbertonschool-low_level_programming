#include <stdlib.h>
#include <string.h>
#include "lists.h"

/**
 * add_node_end - adds a new node at the end of a list_t list
 * @head: address of the pointer to the first node
 * @str: string to store in the new node
 *
 * Return: address of the new element, or NULL if it fails
 */
list_t *add_node_end(list_t **head, const char *str)
{
	list_t *new;
	list_t *temp;
	unsigned int len;

	if (str == NULL)
		return (NULL);

	new = malloc(sizeof(list_t));
	if (new == NULL)
		return (NULL);

	new->str = strdup(str);
	if (new->str == NULL)
	{
		free(new);
		return (NULL);
	}

	len = 0;
	while (str[len] != '\0')
		len++;

	new->len = len;
	new->next = NULL;

	/* if list is empty */
	if (*head == NULL)
	{
		*head = new;
		return (new);
	}

	/* traverse to last node */
	temp = *head;
	while (temp->next != NULL)
		temp = temp->next;

	/* link new node at the end */
	temp->next = new;

	return (new);
}
