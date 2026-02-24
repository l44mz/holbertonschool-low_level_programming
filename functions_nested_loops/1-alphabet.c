#include "main.h"
/**
 * 1-alphabet.c - prints the alphabet in lowercase
 * print_ alphabet: function that prints the alphabet,
 * in lowercase, followed by a new line.
 * return: void
 *
 */
void print_alphabet(void)
{

	char letter = 'a';

	for (letter = 'a'; letter <= 'z'; letter++)
	{

		_putchar(letter);
	}
	_putchar('\n');
}
