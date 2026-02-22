#include "main.h"

/**
 * reverse_array - reverses the content of an array of integers
 * @a: array
 * @n: number of elements
 *
 * Return: nothing
 */
void reverse_array(int *a, int n)
{
	int i;
	int temp;

	i = 0;
	while (i < n / 2)
	{
		temp = a[i];
		a[i] = a[n - 1 - i];
		a[n - 1 - i] = temp;
		i++;
	}
}
