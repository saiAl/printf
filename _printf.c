#include "main.h"

/**
 * _printf - function that printf output to stdout
 * @format: character string.
 * Return: the number of character printed to stdout
 */

int _printf(const char *format, ...)
{
	va_list args;
	int length;

	if (!format)
		return (-1);

	length = strlen(format);
	if (length <= 0)
		return (-1);


	va_start(args, format);
	length = _controller(args, format);

	_putchar(-1);
	va_end(args);

	return (length);
}
