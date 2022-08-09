#include "main.h"
/**
 * print_int_number - prints an integer number
 * @n: int value
 *
 * Return: 0 on success
 */
int print_int_number(int n)
{
	unsigned int num;
	int count = 0;

	num = n;
	if (n < 0)
	{
		_putchar('-');
		count++;
		num *= -1;
	}
	if (num <= 9)
	{
		count += _putchar('0' + num);
		return (count);
	}
	if (num > 9)
	{
		count += print_int_number(num / 10) + 1;
		_putchar('0' + num % 10);
		return (count);
	}
	return (0);
}
