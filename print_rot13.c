#include "main.h"
/**
 * print_rot13 - print string with rot13
 * @ap: arg list
 * Return: number of printed char
 */

int print_rot13(va_list ap)
{
	int sum = 0;
	char *str, *argument = va_arg(ap, char*);

	if (!argument)
	{
		sum += _puts("%R", 0);
		return (sum);
	}

	str = convert_rot13(argument);
	if (!str)
		return (0);
	sum = _puts(str, 0);
	free(str);
	return (sum);
}
