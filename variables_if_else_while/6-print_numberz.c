#include <stdio.h>

/**
 * main - prints base 10 digits starting from 0
 *
 * Return: Always 0
 */
int main(void)
{
	int c;

	for (c = '0'; c <= '9'; c++)
	{
		if (c != 'e' && c != 'q')
			putchar(c);
	}

	putchar('\n');

	return (0);
}
