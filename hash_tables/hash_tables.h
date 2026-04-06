#ifndef HASH_TABLES_H
#define HASH_TABLES_H

#include <stdlib.h>

/**
 * struct hash_node_s - Node of a hash table
 * @key: The key (string)
 * @value: The value (string)
 * @next: Pointer to the next node (for collisions)
 */
typedef struct hash_node_s
{
    char *key;
    char *value;
    struct hash_node_s *next;
} hash_node_t;

/**
 * struct hash_table_s - Hash table structure
 * @size: The size of the array
 * @array: Array of pointers to nodes
 */
typedef struct hash_table_s
{
    unsigned long int size;
    hash_node_t **array;
} hash_table_t;

/* prototype */
hash_table_t *hash_table_create(unsigned long int size);

#endif
