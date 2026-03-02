#include "main.h"
/**
 * puts_half -  prints half of a string, followed by a new line.
 *
 *
 * @str: pointer
 * Return: void
 */
void puts_half(char *str)
{
	int i = 0, length = 0, n;

	while (str[i++])
		length++;

	if ((length % 2) == 0)
		n = length / 2;

	else
		n = (length + 1) / 2;

	for (i = 0; i < length; i += 2)
		_putchar(str[i]);

	_putchar('\n');
}
