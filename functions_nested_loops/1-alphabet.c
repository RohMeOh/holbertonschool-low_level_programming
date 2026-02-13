#include "main.h"

/**
 * print_alphabet - prints the alphabet in lowercase
 *
 * Description: Prints a-z followed by a new line
 */
void print_alphabet(void)
{
	char c;

	for (c = 'a'; c <= 'z'; c++)
	{
		_putchar(c);
	}

	_putchar('\n');
}
