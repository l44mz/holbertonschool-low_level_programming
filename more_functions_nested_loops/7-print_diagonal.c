#include "main.h"

/**
 * print_diagonal - draws a diagonal line on the terminal.
 * @n: the number of times the character \ should be printed
 * Return: void
 */
void print_diagonal(int n)
{
	int a, i;

	if (n > 0)
	{
		for (a = 0; a < n; a++)
		{
			for (i = 0; i < a; i++)
			{
				_putchar(' ');
			}
			_putchar('\\');
			_putchar('\n');

		}
	}
}
