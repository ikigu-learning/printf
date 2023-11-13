#ifndef MAIN_H
#define MAIN_H

int _printf(const char *format, ...);

int print_as_is(int *i, const char *format);

int print_char(int *i, void *ptr);

int print_string(int *i, void *ptr);

int print_percent_char(int *i, void *ptr);

/**
 * struct print_f - a struct
 * @converter: a formatter
 * @f: function to be called
*/

struct print_f
{
	char converter;

	int (*f)(int *, void *);
};

typedef struct print_f print_f;

#endif
