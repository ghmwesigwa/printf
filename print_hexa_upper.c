#include "main.h"
/**
 * print_h_u - print hexa upper
 * @list: arg list
 * Return: number of printed char
 */

int print_h_u(va_list list)
{
	char *str;
	int sum;

	str = convert_base(va_arg(list, unsigned int), 16, 1);
	sum = _puts(str, 0);
	free(str);
	return (sum);
}
