#include "main.h"

/**
 * _puts - prints a string
 * @str: string
 * Return: string
 */

int _puts(char *str)
{
	char *aq = str;

	while (*str)
		_putchar(*str++);
	return (str - aq);
}

/**
 * _putchar - writes the character c
 * @c: character
 * Return: 1.
 */

int _putchar(int c)
{
	static int io;
	static char buf[OUTPUT_BUF_SIZE];

	if (c == BUF_FLUSH || io >= OUTPUT_BUF_SIZE)
	{
		write(1, buf, io);
		io = 0;
	}
	if (c != BUF_FLUSH)
		buf[io++] = c;
	return (1);
}
