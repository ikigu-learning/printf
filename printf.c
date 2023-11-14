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
			char character = va_arg(arguments, int);

			bytes_written += write(1, &character, 1);
			i += 2;
			continue;
		}
		else if (format[i + 1] == 's')
		{
			char *string = va_arg(arguments, char *);

			bytes_written += write(1, string, strlen(string));
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
			int number = va_arg(arguments, int);

			char buffer[20];
			int j = 0;
			int beginning, end;

			if (number == 0)
			{
				bytes_written += write(1, "0", 1);
				i += 2;
				continue;
			}

			if (number < 0)
			{
				bytes_written += write(1, "-", 1);
				number = -number;
			}

			while (number > 0)
			{
				buffer[j++] = '0' + (number % 10);
				number /= 10;
			}

			buffer[j] = '\0';

			beginning = 0, end = j - 1;

			while (beginning < end)
			{
				char b = *(buffer + beginning);
				char e = *(buffer + end);

				if (beginning == end || beginning > end)
				{
					break;
				}

				*(buffer + beginning) = e;
				*(buffer + end) = b;

				beginning++;
				end--;
			}

			bytes_written += write(1, buffer, j);
			i += 2;
			continue;
		}
		else if (format[i + 1] == 'u')
		{
			unsigned int number = va_arg(arguments, unsigned int);

			char buffer[20];
			int j = 0;
			int beginning, end;

			if (number == 0)
			{
				bytes_written += write(1, "0", 1);
				i += 2;
				continue;
			}

			while (number > 0)
			{
				buffer[j++] = '0' + (number % 10);
				number /= 10;
			}

			buffer[j] = '\0';

			beginning = 0, end = j - 1;

			while (beginning < end)
			{
				char b = *(buffer + beginning);
				char e = *(buffer + end);

				if (beginning == end || beginning > end)
				{
					break;
				}

				*(buffer + beginning) = e;
				*(buffer + end) = b;

				beginning++;
				end--;
			}

			bytes_written += write(1, buffer, j);
			i += 2;
			continue;
		}
		i++;
	}

	va_end(arguments);

	return (bytes_written);
}
