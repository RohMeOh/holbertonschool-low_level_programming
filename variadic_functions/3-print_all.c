#include "variadic_functions.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * print_all - prints anything
 * @format: list of types of arguments
 *
 * Return: nothing
 */
void print_all(const char * const format, ...)
{
	int i = 0;
	char *s;
	char *sep = "";
	va_list args;

	va_start(args, format);

	while (format && format[i])
	{
		if (format[i] == 'c')
			printf("%s%c", sep, va_arg(args, int)), sep = ", ";
		if (format[i] == 'i')
			printf("%s%d", sep, va_arg(args, int)), sep = ", ";
		if (format[i] == 'f')
			printf("%s%f", sep, va_arg(args, double)), sep = ", ";
		if (format[i] == 's')
		{
			s = va_arg(args, char *);
			if (!s)
				s = "(nil)";
			printf("%s%s", sep, s);
			sep = ", ";
		}
		i++;
	}

	printf("\n");
	va_end(args);
}
