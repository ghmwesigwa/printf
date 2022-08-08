#include "main.h"
/**
* picker - search and return the right print_ function
* @s: array
* Return: return a function
**/

int i;

int (*picker(char s))(va_list)
{
	op_t operations[] = {
		{"c", print_char},
		{"s", print_string},
		{"%", print_percent},
		{"d", print_integer},
		{"i", print_integer},
		{"b", print_binary},
		{"r", print_reversed},
		{"R", rot13},
		{"u", unsigned_integer},
		{"o", print_octal},
		{"x", print_hex},
		{"X", print_heX},
		{NULL, NULL}
	};
	
	for (i = 0; operations[i].c != NULL; i++)
	{
		if (*operations[i].c == s)
			return (operations[i].f);
	}
	return (NULL);
}
