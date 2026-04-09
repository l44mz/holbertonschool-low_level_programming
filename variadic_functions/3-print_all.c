#include <stdio.h>
#include <stdarg.h>
#include "variadic_functions.h"

/**
 * struct fmt_s - maps a format char to a print function
 * @t: the format character
 * @f: the corresponding print function
 */
struct fmt_s
{
	char t;
	void (*f)(va_list);
};

/**
 * print_char - prints a char from va_list
 * @args: the argument list
 */
void print_char(va_list args)
{
	printf("%c", va_arg(args, int));
}

/**
 * print_int - prints an int from va_list
 * @args: the argument list
 */
void print_int(va_list args)
{
	printf("%d", va_arg(args, int));
}

/**
 * print_float - prints a float from va_list
 * @args: the argument list
 */
void print_float(va_list args)
{
	printf("%f", va_arg(args, double));
}

/**
 * print_string - prints a string from va_list
 * @args: the argument list
 */
void print_string(va_list args)
{
	char *s;

	s = va_arg(args, char *);
	printf("%s", s ? s : "(nil)");
}

/**
 * print_all - prints anything based on format string
 * @format: list of types of arguments passed to the function
 */
void print_all(const char * const format, ...)
{
	va_list args;
	int i;
	char sep;
	struct fmt_s table[] = {
		{'c', print_char},
		{'i', print_int},
		{'f', print_float},
		{'s', print_string},
		{0, NULL}
	};
	int j;

	va_start(args, format);
	i = 0;
	sep = 0;
	while (format && format[i])
	{
		j = 0;
		while (table[j].f)
		{
			if (format[i] == table[j].t)
			{
				if (sep)
					printf(", ");
				table[j].f(args);
				sep = 1;
			}
			j++;
		}
		i++;
	}
	printf("\n");
	va_end(args);
}
