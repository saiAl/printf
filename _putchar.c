#include "main.h"

/**
 * _putchar - function that print one character.
 * @c: paramater for character
 * Return: 1 on seccuss.
 */

int _putchar(char c)
{
	static char *buffer;
	static int count;

	if (buffer == NULL)
		buffer = malloc(BUFF);

	if (c == -1 || count == BUFF)
	{
		write(1, buffer, count);
		count = 0;
	}

	if (c != -1)
		buffer[count++] = c;

	if (c == -1 && buffer != NULL)
	{
		free(buffer);
		buffer = NULL;
	}

	return (1);
}
