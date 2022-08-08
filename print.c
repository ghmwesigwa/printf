#include "main.h"
#include "picker.c"

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

    if (format == NULL)
        return (-1);

    for (i = 0; format[i] != '\0'; i++) /* Iterates through the main string*/
    {
        if (format[i] == '%')
        {
            if (format[i + 1] == '%')
            {
                total_len += _write_char(format[i]);
                i++;
            }
            else if (format[i + 1] != '\0')
            {
                function = picker(format[i + 1]);
                total_len += (function ? function(arg_list) : _write_char(format[i]) + _write_char(format[i + 1]));
                i++;
            }
        }
        else
        {
            total_len += _write_char(format[i]);
        }
    }
    va_end(arg_list);
    return (total_len);
}
