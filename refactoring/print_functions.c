#include <string.h>
#include <unistd.h>
#include "main.h"

/**
* print_as_is - prints non-converted character
* @i: a counter variable
* @format: the format of string to put
*
* Return: number of bytes written
*/

int print_as_is(int i, const char *format)
{
	return (write(1, (format + i), 1));
}

/**
* print_char - prints converted character
* @i: a counter variable
* @character: the character to print
*
* Return: number of bytes written
*/

int print_char(int i, char character)
{
	i = i + 2;
	return (write(1, &character, 1));
}

/**
* print_string - prints converted string
* @i: a counter variable
* @string: the string to print
*
* Return: number of bytes written
*/

int print_string(int i, char *string)
{
	i = i + 2;
	return (write(1, string, strlen(string)));
}

/**
* print_percent_char - prints percent character
* @i: a counter variable
* @character: character to print
*
* Return: number of bytes written
*/

int print_percent_char(int i, char character)
{
	i = i + 2;
	return (write(1, &character, 1));
}
