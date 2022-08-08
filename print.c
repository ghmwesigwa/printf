#include "main.h"
/**
 * _printf - custom printf version
 * @format: initial string with all identifiers
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	int total_len = 0, i = 0;
	va_list list;
	char *buffer, *start;
	int (*function)(va_list);
	
	va_start(list, format), buffer = malloc(sizeof(char) * 1024);;
	
	if (format == NULL)
		return (-1);
	
	if (!format[i])
		return (0);
	
	
	
	
	
	
  
  
}
