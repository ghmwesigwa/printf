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
	int (*function)(va_list, flags_t *);
	flags_t flags = {0, 0, 0};

	
	va_start(list, format);
	
	if (format == NULL)
		return (-1);
	
	if (!format[i])
		return (0);
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '%')
			{	total_len += _putchar('%');
				continue;
			}
			while (get_flag(format[i], &flags))
				format[i + 1];
			function = get_print(format[i]);
			total_len += (function) ? function(list, &flags) : _printf("%%%c", format[i]);
		}
		else
			total_len += _putchar(format[i]);
		i++;
	}
	_putchar(-1);
	va_end(list);
	return (total_len);
	
	
}
