#include "main.h"

/**
 * _printf - custom printf version
 * @format: initial string with all identifiers
 * Return: number of characters printed
 **/

int _printf(const char *format, ...)
{
	int i, j = 0, buff_count = 0, prev_buff_count = 0;
	char buffer[2000];
	va_list arg;
	func_id f_list[] = {
		{'c', print_char},
		{'s', print_str},
		{'i', print_int},
		{'d', print_int},
		{'%', print_perc},
		{'b', print_bin},
		{'o', print_oct},
		{'x', print_hex},
		{'X', print_X},
		{'u', print_uint},
		{'R', print_R13},
		{'r', print_rev},
		{'\0', NULL}};

	if (!format)
		return (-1);
	va_start(arg, format);
	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			i++;
			prev_buff_count = buff_count;
			for (j = 0; f_list[j].t != '\0'; j++)
			{
				if (format[i] == '\0')
					break;
				if (format[i] == f_list[j].t)
				{
					buff_count = f_list[j].f(buffer, arg, buff_count);
					break;
				}
			}
			if (buff_count == prev_buff_count && format[i])
				i--, buffer[buff_count] = format[i], buff_count++;
		}
		else
			buffer[buff_count] = format[i], buff_count++;
	}
	va_end(arg);
	buffer[buff_count] = '\0';
	print_buff(buffer, buff_count);
	return (buff_count);
