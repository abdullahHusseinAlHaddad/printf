#include "main.h"

/**
 * print_from_to - print a range of char addresses
 * @start: starting address
 * @stop: stopping address
 * @except: except address
 * Return: number
 */

int print_from_to(char *start, char *stop, char *except)
{
	int su = 0;

	while (start <= stop)
	{
		if (start != except)
			su += _putchar(*start);
		start++;
	}
	return (su);
}

/**
 * print_rev - print string in reverse
 * @ap: string
 * @params: the parameter
 * Return: number
 */

int print_rev(va_list ap, params_t *params)
{
	int ln, sm = 0;
	char *str = va_arg(ap, char *);
	(void)params;

	if (str)
	{
		for (ln = 0; *str; str++)
			ln++;
		str--;
		for (; ln > 0; ln--, str--)
			sm += _putchar(*str);
	}
	return (sm);
}

/**
 * print_rot13 - print string in rot13
 * @ap: string
 * @params: the parameter
 * Return: number
 */

int print_rot13(va_list ap, params_t *params)
{
	int in, dex;
	int count = 0;
	char arr[] =
		"NOPQRSTUVWXYZABCDEFGHIJKLM      nopqrstuvwxyzabcdefghijklm";
	char *a = va_arg(ap, char *);
	(void)params;

	in = 0;
	dex = 0;
	while (a[in])
	{
		if ((a[in] >= 'A' && a[in] <= 'Z')
		    || (a[in] >= 'a' && a[in] <= 'z'))
		{
			dex = a[in] - 65;
			count += _putchar(arr[dex]);
		}
		else
			count += _putchar(a[in]);
		in++;
	}
	return (count);
}
