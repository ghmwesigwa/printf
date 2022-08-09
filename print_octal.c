#include "main.h"
/**
 * print_octal - print number octal base
 * @list: arg list
 * Return: number of printed char
 */

int print_o(va_list list)
{
	char *str;
	int sum;

	str = convert_base(va_arg(list, unsigned int), 8, 0);
	sum = _puts(str, 0);
	free(str);
	return (sum);
}
