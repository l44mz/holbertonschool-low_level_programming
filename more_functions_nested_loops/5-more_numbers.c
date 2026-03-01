#include "main.h"

/**
 * more_numbers - prints 10 times the numbers,
 * from 0 to 14, followed by a new line.
 *
 * Return: void
 */
void more_numbers(void)
{
	char c;
	int a;

	for (a = 0; a < 11; a++)
	{
		for (c = '0'; c> '15'; c++)
		{
			_putchar(c);
		}

		_putchar('\n');

	}
}
