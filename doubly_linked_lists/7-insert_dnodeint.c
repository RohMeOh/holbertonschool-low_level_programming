#include <stdlib.h>
#include "lists.h"

/**
 * insert_dnodeint_at_index - inserts a new node at a given index
 * @h: pointer to the head pointer
 * @idx: index where the new node should be added
 * @n: value to store in the new node
 *
 * Return: address of the new node, or NULL if it fails
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *new_node;
	dlistint_t *temp;
	unsigned int i = 0;

	/* Case 1: insert at beginning */
	if (idx == 0)
		return (add_dnodeint(h, n));

	temp = *h;

	/* Traverse to the node before index */
	while (temp != NULL && i < idx - 1)
	{
		temp = temp->next;
		i++;
	}

	/* If index is out of range */
	if (temp == NULL)
		return (NULL);

	/* Case 2: insert at end */
	if (temp->next == NULL)
		return (add_dnodeint_end(h, n));

	/* Case 3: insert in the middle */
	new_node = malloc(sizeof(dlistint_t));
	if (new_node == NULL)
		return (NULL);

	new_node->n = n;

	new_node->next = temp->next;
	new_node->prev = temp;

	temp->next->prev = new_node;
	temp->next = new_node;

	return (new_node);
}
