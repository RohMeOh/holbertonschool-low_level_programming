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
	list_t *new, *temp;
	unsigned int len = 0;

	if (str == NULL)
		return (NULL);
	new = malloc(sizeof(list_t));
	if (new == NULL)
		return (NULL);
	new->str = strdup(str);
	if (new->str == NULL)
		return (free(new), NULL);
	while (str[len] != '\0')
		len++;
	new->len = len;
	new->next = NULL;
	if (*head == NULL)
		return (*head = new, new);
	temp = *head;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = new;
	return (new);
}
