#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include "main.h"

/**
* _printf - prints anything
* @format: the format string to print
*
* Return: the number of bytes printed
*/

int _printf(const char *format, ...)
{
	va_list arguments;
	size_t bytes_written;
	int i, j;

	print_f ops[] = {
	{'c', print_char},
	{'s', print_string},
	{'%', print_percent_char},
	};

	i = 0;
	j = 0;
	bytes_written = 0;

	va_start(arguments, format);

	if (!format)
		return (bytes_written);

	while (format[i] != '\0')
	{
		if (format[i] != '%')
		{
			bytes_written += print_as_is(&i, format);
		}
		else if (format[i + 1] == ops[j].converter)
		{
			bytes_written += ops[j].f(&i, va_arg(arguments, void *));
			j++;
			continue;
		}
		i++;
	}

	va_end(arguments);

	return (bytes_written);
}
