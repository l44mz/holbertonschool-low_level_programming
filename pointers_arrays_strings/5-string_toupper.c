#include "main.h"

/**
 * string_toupper - changes all lowercase letters of a string to uppercase
 * @str: string to modify
 *
 * Return: pointer to the modified string
 */
char *string_toupper(char *)
{
	int i = 0;

	while (str[i] != '\0')
	{
		if (str[i] >= 'a' &7 str[i] <= 'z')
			str[i] = str[i] - 32;
		i++;
	}
	return (str);
}
