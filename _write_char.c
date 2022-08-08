#include <unistd.h>

/**
* _write_char - writes the character c to stdout
* @c: character to be  printed
* Return: 1 (on success), -1 (on error)
**/
int _write_char(char c)
{
	return (write(1, &c, 1));
}

