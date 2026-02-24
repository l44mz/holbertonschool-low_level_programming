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

	for (letter = 'a'; letter <= 'z'; letter++)
	{
		for (num = 1; num <= 10; num++)
		{
			_putchar(letter);
		}
	}

	_putchar('\n');
}
