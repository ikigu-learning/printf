#include <stdarg.h>
#include <stddef.h>
#include <unistd.h>
#include <string.h>
#include "main.h"

/**
* rev_string - reverses a string in memory
* @s: The string to reverse
* @length: length of string
*
* Return: Nothing
*/

void rev_string(char *s, int length)
{
	int i = 0;

	int j = length;

	while (i < j)
	{
		char b = *(s + i);

		char e = *(s + j);

		if (i == j || i > j)
		{
			break;
		}

		*(s + i) = e;
		*(s + j) = b;

		i++;
		j--;
	}
}


/**
* print_char - prints for %c
* @arguments: variadic arguments of _printf function
*
* Return: the current byte count
*/

int print_char(va_list arguments)
{
	char character = va_arg(arguments, int);

	return (write(1, &character, 1));
}

/**
* print_string - prints for %s
* @arguments: variadic arguments of _printf function
*
* Return: the current byte count
*/

int print_string(va_list arguments)
{
	char *string = va_arg(arguments, char *);

	return (write(1, string, strlen(string)));
}

/**
* print_int - prints for %d and %i
* @arguments: variadic arguments of _printf function
*
* Return: the current byte count
*/

int print_int(va_list arguments)
{
	int number = va_arg(arguments, int);

	char buffer[20];

	int j = 0;

	if (number == 0)
		return (write(1, "0", 1));

	if (number < 0)
	{
		write(1, "-", 1);
		number = -number;
	}

	while (number > 0)
	{
		buffer[j++] = '0' + (number % 10);
		number /= 10;
	}

	buffer[j] = '\0';

	rev_string(buffer, (j - 1));

	write(1, buffer, j);

	if (number < 0)
		return (j + 1);
	else
		return (j);
}

/**
 * print_unsigned - prints for %u
 * @arguments: variadic arguments of _printf function
 *
 * Return: number of bytes written
*/

int print_unsigned(va_list arguments)
{
	unsigned int number = va_arg(arguments, unsigned int);

	char buffer[20];

	int j = 0;

	if (number == 0)
		return (write(1, "0", 1));

	while (number > 0)
	{
		buffer[j++] = '0' + (number % 10);
		number /= 10;
	}

	buffer[j] = '\0';

	rev_string(buffer, (j - 1));

	return (write(1, buffer, j));
}
