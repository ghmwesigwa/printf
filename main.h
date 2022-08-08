#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h> /* va_list */
#include <stddef.h> /* typedef */
#include <unistd.h> /* write */
#include <stdio.h>  /* malloc, free */
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

#endif
