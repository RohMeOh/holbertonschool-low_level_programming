#include "hash_tables.h"
#include <string.h>

/**
 * _strdup - duplicates a string
 * @str: string to duplicate
 *
 * Return: pointer to duplicated string, or NULL if it fails
 */
char *_strdup(const char *str)
{
	char *copy;
	unsigned int i, len;

	if (str == NULL)
		return (NULL);

	len = 0;
	while (str[len] != '\0')
		len++;

	copy = malloc(sizeof(char) * (len + 1));
	if (copy == NULL)
		return (NULL);

	for (i = 0; i <= len; i++)
		copy[i] = str[i];

	return (copy);
}

/**
 * create_node - creates a new hash table node
 * @key: key of the node
 * @value: value of the node
 *
 * Return: pointer to new node, or NULL if it fails
 */
hash_node_t *create_node(const char *key, const char *value)
{
	hash_node_t *new_node;

	new_node = malloc(sizeof(hash_node_t));
	if (new_node == NULL)
		return (NULL);

	new_node->key = _strdup(key);
	if (new_node->key == NULL)
	{
		free(new_node);
		return (NULL);
	}

	new_node->value = _strdup(value);
	if (new_node->value == NULL)
	{
		free(new_node->key);
		free(new_node);
		return (NULL);
	}

	new_node->next = NULL;
	return (new_node);
}

/**
 * update_node - updates value of an existing node
 * @node: node to update
 * @value: new value
 *
 * Return: 1 if success, 0 if failure
 */
int update_node(hash_node_t *node, const char *value)
{
	char *new_value;

	new_value = _strdup(value);
	if (new_value == NULL)
		return (0);

	free(node->value);
	node->value = new_value;

	return (1);
}

/**
 * hash_table_set - adds an element to the hash table
 * @ht: hash table
 * @key: key, cannot be empty
 * @value: value associated with key
 *
 * Return: 1 if it succeeded, 0 otherwise
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	hash_node_t *tmp, *new_node;
	unsigned long int index;

	if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
		return (0);

	index = key_index((const unsigned char *)key, ht->size);
	tmp = ht->array[index];

	while (tmp != NULL)
	{
		if (strcmp(tmp->key, key) == 0)
			return (update_node(tmp, value));
		tmp = tmp->next;
	}

	new_node = create_node(key, value);
	if (new_node == NULL)
		return (0);

	new_node->next = ht->array[index];
	ht->array[index] = new_node;

	return (1);
}
