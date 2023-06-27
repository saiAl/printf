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

	_write(-1);
	va_end(args);

	return (length);
}

#include "main.h"

/**
 * _controller - function that handles the different functionality of printf flag, width ...
 * @args: list of argument provided from _printf
 * @string: a string to holds last fixed paramater (format) from _printf
 * Return: size of the printed characters on seccuss, -1 on failure.
 */

int _controller(va_list args, const char *string)
{
	int counter;
	int size;
	int func_return;

	size = 0;
	func_return = 0;

	for (counter = 0; string[counter] != '\0'; counter++)
	{
		if (string[counter] == '%')
		{
			func_return = percent(args, string, &counter);
			if (func_return == -1)
				return (-1);

			size += func_return;
			continue;
		}
		_write(string[counter]);
		size += 1;
	}

	return (size);
}

/**
 * percent - function that handles the percent sign (%)
 * @args: list of arguemtns from _printf
 * @string: string characters from _controller
 * @count: paramater to store the address of the current counter at (%) place in _contriller
 * Return: the bytes of characters processed, -1 on failure
 */

int percent(va_list args, const char *string, int *count)
{
	int size;
	int ch, check;

	*count += 1;

	if (string[*count] == '\0')
		return (-1);

	if (string[*count] == '%')
	{
		_write('%');
		return (1);
	}
	check = string[*count];
	switch (check)
	{
		case 'c':
			ch = print_char(args);
			_write(ch);
			size = 1;
			break;
		default:
			size = 1;
			break;
	}
	*count += 1;
	return (size);
}
