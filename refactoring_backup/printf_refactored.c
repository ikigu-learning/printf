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
	int i;

	i = 0;
	bytes_written = 0;

	va_start(arguments, format);

	if (!format)
		return (0);

	while (format[i] != '\0')
	{
		if (format[i] != '%')
		{
			bytes_written += print_as_is(&i, format);
		}
		else if (format[i + 1] == 'c')
		{
			bytes_written += print_char(&i, va_arg(arguments, int));
			continue;
		}
		else if (format[i + 1] == 's')
		{
			bytes_written += print_string(&i, va_arg(arguments, char *));
			continue;
		}
		else if (format[i + 1] == '%')
		{
			bytes_written += print_percent_char(&i, '%');
			continue;
		}
		i++;
	}

	va_end(arguments);

	return (bytes_written);
}
