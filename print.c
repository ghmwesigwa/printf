#include "main.h"

/**
 * _printf - custom printf version
 * @format: initial string with all identifiers
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	int total_len = 0, i;
	va_list list;
	int (*function)(va_list);
	
	va_start(list, format);
	
	if (format == NULL)
		return (-1);

	for (i = 0; format[i] != '\0'; i++) /* Iterates through the main str*/
	{
		if (format[i] == '%') /*Checks for format specifiers*/
		{
			if (format[i + 1] == '%')
			{	total_len += _putchar(format[i]);
				i++;
			}
			else if (format[i + 1] != '\0')
			{
				function = picker(format[i + 1]);
				total_len += (function ? function(list) : _write_char(format[i]) + _write_char(format[i + 1]));
				i++;
				
			}

		}
		else
			total_len += _putchar(format[i]);

	}
	va_end(list);
	return (total_len);
	
	
}
