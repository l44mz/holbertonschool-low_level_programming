#include "main.h"

/**
 * swap - swaps the values of two integers.
 *
 * @a: pointer to integer 1.
 * @b: pointer to integer 2.
 * Return: void
 */
void swap_int(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;

}
