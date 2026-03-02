#include "main.h"
/**
 * puts2 -  prints every other character of a string, starting with 
 * the first character, followed by a new line.
 *
 * @str: pointer
 * Return: void
 */
void puts2(char *str)
{

	while (*str)
	{
		_putchar(*str);
		str += 2;
	}

	_putchar('\n');

}
