#include <stdio.h>
#include <main.h>
/**
 * print_name - prints a name using a function pointer
 * @name: the name to print
 * @f: pointer to a function that prints the name
 *
 * Description: This function calls another function `f`
 *              to print the given name.
 */
void print_name(char *name, void (*f)(char *))
{
	if (name == NULL || f == NULL)
		return;

	f(name);
}
