#include "main.h"

/**
 * print_alphabet_x10 - prints the alphabet ten times
 *
 * Return: void
 */
void print_alphabet_x10(void)
{
	char letter;
	int num;

	for (num = 1; num <= 2; num++)
	{
		for (letter = 1; letter <= 10; letter++)
		{
			_putchar(letter);
		}
	}

	_putchar('\n');
}
