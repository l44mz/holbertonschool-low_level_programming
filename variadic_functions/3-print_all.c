#include "variadic_functions.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * print_all - prints anything based on format string
 * @format: list of types of arguments passed
 *
 * Description: c = char, i = int, f = float, s = char *
 *              Prints (nil) for NULL strings.
 *              Any other char is ignored.
 */
void print_all(const char * const format, ...)
{
	va_list args;
	unsigned int i = 0;
	char *str;
	int printed = 0;

	va_start(args, format);

	if (format != NULL)
	{
		while (format[i])
		{
			if (printed)
				printf(", ");

			if (format[i] == 'c')
			{
				printf("%c", va_arg(args, int));
				printed = 1;
			}
			if (format[i] == 'i')
			{
				printf("%d", va_arg(args, int));
				printed = 1;
			}
			if (format[i] == 'f')
			{
				printf("%f", va_arg(args, double));
				printed = 1;
			}
			if (format[i] == 's')
			{
				str = va_arg(args, char *);
				if (str == NULL)
					printf("(nil)");
				else
					printf("%s", str);
				printed = 1;
			}

			i++;
		}
	}

	va_end(args);
	printf("\n");
}
