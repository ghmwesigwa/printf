#include "main.h"
/**
 * print_s_r - reverse a string
 * @list: arg list
 * Return: number printed char
 */
int print_s_r(va_list list)
{
	char *arg = va_arg(list, char *), *str;
	int size, left, limit, right, sum = 0;

	if (!arg)
	{
		sum += _puts("%r", 0);
		return (sum);
	}
	size = _strlen_recursion(arg);
	right = size - 1;
	limit = (size % 2 == 0) ? (size + 1) / 2 : (size / 2);
	str = malloc(sizeof(char) * (size + 1));

	if (str == NULL)
		return (0);
	if (size % 2 != 0)
		str[limit] = arg[limit];

	for (left = 0; left < limit; left++)
	{
		str[left] = arg[right];
		str[right] = arg[left];
		right--;
	}
	str[size] = '\0';

	sum = _puts(str, 0);
	free(str);

	return (sum);
}

