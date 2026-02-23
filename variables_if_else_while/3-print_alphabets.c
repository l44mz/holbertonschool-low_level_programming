#include <stdio.h>
/**
 * main - Prints the last digit of a randomly generated number
 *        and whether it is greater than 5, less than 6, or 0.
 *
 * Return: Always 0.
 */
int main(void)
{
	char ch = 'a';
	char c = 'A';

	for (ch = 'a'; ch <= 'z'; ch++)
	{
		putchar (ch);
	}
	for  (c = 'A'; c<= 'Z'; c++)
	{
		putchar (c);
	}
	putchar ('\n');
	return (0);
}
