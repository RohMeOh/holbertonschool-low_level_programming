#include "main.h"

/**
 * puts_half - prints the second half of a string
 * @str: pointer to the string
 *
 * Return: nothing
 */
void puts_half(char *str)
{
	int len;
	int i;
	int start;

	len = 0;

	while (str[len] != '\0')
	{
		len++;
	}

	start = (len + 1) / 2;

	for (i = start; i < len; i++)
	{
		_putchar(str[i]);
	}

	_putchar('\n');
}
