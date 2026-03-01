#include "main.h"
#include <stdio.h>
/**
 * _isupper - Checks for uppercase characters.
 *
 * @c: The character to be checked
 */

int _isupper(int c)
{

	if (c >= 'A' && c <= 'Z')
	{
		return (1);

	}

	else
	{
		return (0);

	}

}
