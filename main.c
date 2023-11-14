#include <limits.h>
#include <stdio.h>
#include "main.h"

/**
* main - Entry point
*
* Return: Always 0
*/


int main(void)
{
	int len, len2;
	unsigned int ui;

	len = _printf("Let's try to printf a simple sentence.\n");
	len2 = printf("Let's try to printf a simple sentence.\n");
	ui = (unsigned int)INT_MAX + 1024;

	_printf("Length:[%d, %i]\n", len, len);
	printf("Length:[%d, %i]\n", len2, len2);

	_printf("String:[%s]\n", "I am a string !");
	printf("String:[%s]\n", "I am a string !");

	_printf("Characters:[%c, %c, %c]\n", 'H', 'o', 'e');
	printf("Characters:[%c, %c, %c]\n", 'H', 'o', 'e');

	_printf("Unsigned:[%u]\n", ui);
	printf("Unsigned:[%u]\n", ui);

	return (0);
}

