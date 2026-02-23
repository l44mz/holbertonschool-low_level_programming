#include <stdio.h>
/**
 * main - Prints numbers from 0-9
 *
 *
 * Return: Always 0.
 */
int main(void)
{
	int num = 0;

	for (num = 0; num <= 9; num++)
	{
		putchar (num + '0');
	}
	putchar ('\n');
	return (0);
}
