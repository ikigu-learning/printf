#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
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
		return (bytes_written);

	while (format[i] != '\0')
	{
		if (format[i] != '%')
		{
			bytes_written += write(1, &format[i], 1);
		}
		else if (format[i + 1] == 'c')
		{
			bytes_written += print_char(arguments);
			i += 2;
			continue;
		}
		else if (format[i + 1] == 's')
		{
			bytes_written += print_string(arguments);
			i += 2;
			continue;
		}
		else if (format[i + 1] == '%')
		{
			char percent = '%';

			bytes_written += write(1, &percent, 1);
			i += 2;
			continue;
		}
		else if (format[i + 1] == 'd' || format[i + 1] == 'i')
		{
			bytes_written += print_int(arguments);
			i += 2;
			continue;
		}
		else if (format[i + 1] == 'u')
		{
			bytes_written += print_unsigned(arguments);
			i += 2;
			continue;
		}
		i++;
	}

	va_end(arguments);

	return ((int)bytes_written);
}
