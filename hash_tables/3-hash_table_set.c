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
	unsigned int len, i;

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
 * hash_table_set - adds an element to the hash table
 * @ht: hash table
 * @key: key, cannot be empty
 * @value: value associated with key
 *
 * Return: 1 if it succeeded, 0 otherwise
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	hash_node_t *new_node, *tmp;
	unsigned long int index;
	char *dup_value;

	if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
		return (0);

	index = key_index((const unsigned char *)key, ht->size);
	tmp = ht->array[index];

	while (tmp != NULL)
	{
		if (strcmp(tmp->key, key) == 0)
		{
			dup_value = _strdup(value);
			if (dup_value == NULL)
				return (0);
			free(tmp->value);
			tmp->value = dup_value;
			return (1);
		}
		tmp = tmp->next;
	}

	new_node = malloc(sizeof(hash_node_t));
	if (new_node == NULL)
		return (0);

	new_node->key = _strdup(key);
	if (new_node->key == NULL)
	{
		free(new_node);
		return (0);
	}

	new_node->value = _strdup(value);
	if (new_node->value == NULL)
	{
		free(new_node->key);
		free(new_node);
		return (0);
	}

	new_node->next = ht->array[index];
	ht->array[index] = new_node;

	return (1);
}
