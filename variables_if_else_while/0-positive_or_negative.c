#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * main - prints whether n is positive, zero or negative
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int n;

	srand(time(0));
	n = rand() - RAND_MAX / 2;

	printf("%d ", n);

	if (n > 0)
		printf("is positive");
	else if (n == 0)
		printf("is zero");
	else
		printf("is negative");

	printf("\n");

	return (0);
}
