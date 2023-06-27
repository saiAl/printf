#include "main.h"

/**
 * print_char - function to print char
 * @args: list of arguments from _printf function
 * Return: 1 on seccuss
 */

int print_char(va_list args)
{
	int ch;

	ch = va_arg(args, int);
	_write(ch);

	return (1);
}
