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

int print_as_is(int *i, const char *format)
{
	return (write(1, (format + *i), 1));
}

/**
* print_char - prints converted character
* @i: a counter variable
* @ptr: void pointer
*
* Return: number of bytes written
*/

int print_char(int *i, void *ptr)
{
	char *character;

	*i = *i + 2;
	character = (char *)ptr;

	return (write(1, character, 1));
}

/**
* print_string - prints converted string
* @i: a counter variable
* @ptr: void ptr
*
* Return: number of bytes written
*/

int print_string(int *i, void *ptr)
{
	char *string;

	*i = *i + 2;
	string = (char *)ptr;

	return (write(1, string, strlen(string)));
}

/**
* print_percent_char - prints percent character
* @i: a counter variable
* @ptr: void ptr
*
* Return: number of bytes written
*/

int print_percent_char(int *i, void *ptr)
{
	char *percent;

	percent = (char *)ptr;
	*i = *i + 2;

	return (write(1, percent, 1));
}

