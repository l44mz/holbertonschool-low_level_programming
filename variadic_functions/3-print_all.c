#include <stdio.h>
#include <stdarg.h>
#include "variadic_functions.h"

/**
 * print_all - prints anything based on format string
 * @format: list of types of arguments passed to the function
 */
void print_all(const char * const format, ...)
{
	va_list args;
	int i;
	char *str;
	char sep;

	va_start(args, format);
	i = 0;
	sep = 0;
	while (format && format[i])
	{
		if (sep)
			printf(", ");
		if (format[i] == 'c')
		{
			printf("%c", va_arg(args, int));
			sep = 1;
		}
		if (format[i] == 'i')
		{
			printf("%d", va_arg(args, int));
			sep = 1;
		}
		if (format[i] == 'f')
		{
			printf("%f", va_arg(args, double));
			sep = 1;
		}
		if (format[i] == 's')
		{
			str = va_arg(args, char *);
			printf("%s", str ? str : "(nil)");
			sep = 1;
		}
		i++;
	}
	printf("\n");
	va_end(args);
}
