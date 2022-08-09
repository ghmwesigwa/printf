#include "main.h"

/**
* func_picker - search and return the right print_ function
* @s: array
* Return: return a function
**/


int (*func_picker(char s))(va_list)
{
	func_id f_list[] = {
		{"c", print_c},
		{"s", print_s},
		{"%", print_p}

	};
	int i;

	for (i = 0; f_list[i].c != NULL; i++)
	{
		if (*f_list[i].c == s)
			return (f_list[i].f);
	}
	return (NULL);
}

/**
 * _printf - custom printf version
 * @format: initial string with all identifiers
 * Return: number of characters printed
 **/
int _printf(const char *format, ...)
{
	int total_len = 0;
    int i;
    va_list arg_list;
    int (*function)(va_list);

    va_start(arg_list, format);

    if (format[0] == '%' && format[1] == '\0')
	    return (-1);

    for (i = 0; format[i] != '\0'; i++) /* Iterates through the main string*/
    {
        if (format[i] == '%')
        {
            if (format[i + 1] == '%')
            {
                total_len += _putchar(format[i]);
                i++;
            }
            else if (format[i + 1] != '\0')
            {
                function = func_picker(format[i + 1]);
                total_len += (function ? function(arg_list) : _putchar(format[i]) + _putchar(format[i + 1]));
                i++;
            }
        }
        else
        {
            total_len += _putchar(format[i]);
        }
    }
    va_end(arg_list);
    return (total_len);
}
