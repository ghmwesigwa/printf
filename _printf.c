#include "main.h"
#include <stdio.h>

/**
 * get_func - select funciton for conversion
 * @c: char to use for selection
 * Return: pointer to function
 */
int (*get_func(const char c))(va_list)
{
	int i = 0;

	function_identifier f[] = {
		{"c", print_char},
		{"s", print_str},
		{"S", print_str_x},
		{"%", print_percent},
		{"d", print_int},
		{"b", print_binary},
		{"i", print_int},
		{"u", print_unsigned},
		{"o", print_octal},
		{"x", print_hexa_lower},
		{"X", print_hexa_upper},
		{"p", print_ptr},
		{"r", print_str_reverse},
		{"R", print_rot13},
	};

	while (i < 14)
	{
		if (c == f[i].c[0])
			return (f[i].f);
		i++;
	}
	return (NULL);
}

/**
 * _printf - function to perform like printf
 * @format: format astring
 * Return: number of characters printed excluding the null byte
 */
int _printf(const char *format, ...)
{
	int i = 0, sum = 0, j, p = 0;
	int (*function)();

	va_list ap;

	va_start(ap, format);

	if (!format || (format[0] == '%' && format[1] == '\0'))
		return (-1);

	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);

	while (format[i])
	{
		if (format[i] == '%')
		{
			j = check_modifier(format[i + 1]);

			if (j == 0)
			{
				if (format[i + 1] != '\0')
					function = get_func(format[i + 1]);
			} else if (j < 0)
			{
				p = 1;
				if (format[i + 1] != '\0')
					function = get_func(format[i + 2]);
			}else
			{
				p = 1;
				sum += j;
				i += j;
				function = get_func(format[i + 1]);
			}
			if (function == NULL)
			{
				_putchar(format[i]);
				sum++;
				i++;
			} else
			{
				sum += function(ap);
				i += 2;
				continue;
			}
		} else
		{
			if (p == 0)
			{
				_putchar(format[i]);
				sum++;
				i++;
			} else
			{
				function = get_func(format[i + 1]);
				if (function == NULL)
				{
					_putchar(format[i]);
					sum++;
					i++;
				} else
				{
					sum += function(ap);
					i += 2;
					continue;
				}
			}
		}
	}
	va_end(ap);
	return (sum);
}

int check_modifier(char s)
{
	int m = 0;

	switch (s)
	{
	case '+':
		_putchar('+');
		m++;
		break;
	case ' ':
		_putchar(' ');
		m++;
		break;
	case '#':
		_putchar('0');
		m++;
		break;
	}
	return (m);
}
