#include "main.h"

/**
 * _puts - function  prints a string with newline
 * @str: the string to be printed
 *
 * Return: void
 */
int _puts(char *str)
{
	char *b = str;

	while (*str)
		_putchar(*str++);
	return (str - b);
}

/**
 * _putchar - function prints a character c to stdout
 * @c: The character to be printed
 *
 * Return: On success 1.
 * on errno is set appropriately,On error, -1 is returned.
 */
int _putchar(int c)
{
	static int i;
	static char buff[OUTPUT_BUF_SIZE];

	if (c == FLUSH_BUF || i >= OUTPUT_BUF_SIZE)
	{
		write(1, buff, i);
		i = 0;
	}
	if (c != FLUSH_BUF)
		buff[i++] = c;
	return (1);
}

