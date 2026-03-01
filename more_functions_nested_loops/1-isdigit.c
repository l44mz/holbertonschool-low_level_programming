#include "main.h"
#include <stdio.h>
/**
 * _isdigit - Checks for a digit.
 *
 * @c: The digit to be checked
 * Return: int
 */
int _isdigit(int c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);

	}

	else
	{
		return (0);
	}



}
