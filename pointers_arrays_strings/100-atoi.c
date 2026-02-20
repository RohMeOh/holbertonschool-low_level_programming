#include "main.h"

/**
 * _atoi - converts a string to an integer
 * @s: string to convert
 *
 * Return: converted integer, or 0 if no digits
 */
int _atoi(char *s)
{
	int i;
	int sign;
	int started;
	unsigned int num;

	i = 0;
	sign = 1;
	started = 0;
	num = 0;

	while (s[i] != '\0')
	{
		if (started == 0)
		{
			if (s[i] == '-')
				sign = -sign;
			else if (s[i] >= '0' && s[i] <= '9')
				started = 1;
		}

		if (started == 1)
		{
			if (s[i] >= '0' && s[i] <= '9')
				num = (num * 10) + (s[i] - '0');
			else
				break;
		}

		i++;
	}

	if (started == 0)
		return (0);

	if (sign < 0)
		return ((int)(0u - num));

	return ((int)num);
}
