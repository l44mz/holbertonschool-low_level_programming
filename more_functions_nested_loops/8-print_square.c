#include "main.h"

/**
 * print_square - prints a square, followed by a new line.
 * @size: size of the square
 * Return: void
 */
void print_square(int size)
{
	int w, a;
	
	if (size <= 0)
	{
		_putchar('\n');
		return;

	}

	for (w = 0; w < size; w++)
	{
		for (a = 0; a < size; a++)
		{
			_putchar('#');
		}

		_putchar('\n');

	}

}
