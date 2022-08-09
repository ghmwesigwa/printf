#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h> /* va_list */
#include <stddef.h> /* typedef */
#include <unistd.h> /* write */
#include <stdio.h> /* malloc, free */
#include <stdlib.h> /* memory allocation, process control, conversions, etc */

/* printf functions */
int _printf(const char *format, ...);

/**
*struct func_identifier - struct
*@c: identifier
*@f: pointer to function that print according to identifier
*/
typedef struct func_identifier
{
	char *c;
	int (*f)(va_list);
} func_id;

/* helper functions */
int _putchar(char c);
int _puts(char *str, int ascii);
int print_c(va_list list);
int print_s(va_list list);
int print_int_number(int n);
int print_p(va_list args __attribute__((unused)));
int convert_alpha_numeric(int nb, int upper);
int print_i(va_list list);
char *convert_base(unsigned long nb, unsigned int base, int upper);


#endif
