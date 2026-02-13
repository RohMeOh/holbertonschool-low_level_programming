#include <stdio.h>

/**
 * main - prints alphabet except q and e
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	char c;

	for (c = 'a'; c <= 'z'; c++)
	{
	    if (c != 'q' && c != 'e')
	        putchar(c);
	}

	return (0);
}
