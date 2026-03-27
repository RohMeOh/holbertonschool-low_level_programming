#include <stdio.h>
#include "lists.h"

/**
 * print_list - prints all elements of a list_t list
 * @h: pointer to the head of the list
 *
 * Return: number of nodes
 */
size_t print_list(const list_t *h)
{
    size_t count = 0;  /* counter for nodes */

    while (h != NULL)  /* loop through the list */
    {
        if (h->str == NULL)
        {
            /* if string is NULL */
            printf("[0] (nil)\n");
        }
        else
        {
            /* print length and string */
            printf("[%u] %s\n", h->len, h->str);
        }

        h = h->next;   /* move to next node */
        count++;       /* increase node count */
    }

    return (count);    /* return total nodes */
}

