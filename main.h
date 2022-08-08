#ifndef MAIN_H
#define MAIN_H
#define INT_BITS (4 * 8)

#include <stdarg.h> /* va_list */
#include <stddef.h> /* typedef */
#include <unistd.h> /* write */
#include <stdio.h> /* malloc, free */
#include <stdlib.h> /* memory allocation, process control, conversions, etc */
#include <limits.h>

/**
*struct func_identifier - struct
*@c: identifier
*@f: pointer to function that print according to identifier
**/
typedef struct func_identifier
{
	char t;
	int (*f)(char *, va_list, int);
} func_id;

/* helper functions */
int buff_append(char *buff_dest, va_list arg, int buff_count, char type);
int print_buff(char *buff, unsigned int nbuff);
int str_len(char *s);
char *_strcpy(char *dest, char *src);

/* printf functions */
int _printf(const char *format, ...);
int print_char(char *buff_dest, va_list arg, int buff_count);
int print_str(char *buff_dest, va_list arg, int buff_count);
int print_int(char *buff_dest, va_list list, int buff_count);
int print_perc(char *buff_dest, va_list arg, int buff_count);
int print_bin(char *buff_dest, va_list arg, int buff_count);
int print_oct(char *buff_dest, va_list arg, int buff_count);
int print_hex(char *buff_dest, va_list arg, int buff_count);
int print_X(char *buff_dest, va_list arg, int buff_count);
int print_uint(char *buff_dest, va_list arg, int buff_count);
int print_rev(char *buff_dest, va_list arg, int buff_count);
int print_R13(char *buff_dest, va_list arg, int buff_count);


#endif
