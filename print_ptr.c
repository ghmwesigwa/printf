#include "main.h"

/**
 * print_ptr - print adress
 * @list: arg void
 * Return: number of printed char
 */
int print_ptr(va_list list)
{
	char *str;
	int sum = 0;
	unsigned long p = (unsigned long) va_arg(list, void*);

	if (!p)
	{
		sum += _puts("(nil)", 0);
		return (sum);
	}

	str = convert_base_pointer(p);
	if (!str)
		return (0);
	sum += _puts("0x", 0);
	sum += _puts(str, 0);
	free(str);
	return (sum);
}
