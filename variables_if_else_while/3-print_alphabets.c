#include <stdio.h>

int main(void)
{
    char c;

    /* Print lowercase */
    for (c = 'a'; c <= 'z'; c++)
    {
        putchar(c);
    }

    /* Print uppercase */
    for (c = 'A'; c <= 'Z'; c++)
    {
        putchar(c);
    }

    putchar('\n');

    return 0;
}
