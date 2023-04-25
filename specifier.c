#include "main.h"

/**
 * get_specifier - find the format function
 * @s: string
 * Return: number
 */

int (*get_specifier(char *s))(va_list ap, params_t *params)
{
	specifier_t specifiers[] = {
		{"c", print_char},
		{"d", print_int},
		{"i", print_int},
		{"s", print_string},
		{"%", print_percent},
		{"b", print_binary},
		{"o", print_octal},
		{"u", print_unsigned},
		{"x", print_hex},
		{"X", print_HEX},
		{"p", print_address},
		{"S", print_S},
		{"r", print_rev},
		{"R", print_rot13},
		{NULL, NULL}
	};
	int io = 0;

	while (specifiers[io].specifier)
	{
		if (*s == specifiers[io].specifier[0])
		{
			return (specifiers[io].f);
		}
		io++;
	}
	return (NULL);
}

/**
 * get_print_func - find the format function
 * @s: the format string
 * @ap: arg pointer
 * @params: the parameter
 * Return: number
 */

int get_print_func(char *s, va_list ap, params_t *params)
{
	int (*f)(va_list, params_t *) = get_specifier(s);

	if (f)
		return (f(ap, params));
	return (0);
}

/**
 * get_flag - find the flag function
 * @s: the string
 * @params: the parameter
 * Return: flag
 */

int get_flag(char *s, params_t *params)
{
	int iq = 0;

	switch (*s)
	{
		case '+':
			iq = params->plus_flag = 1;
			break;
		case ' ':
			iq = params->space_flag = 1;
			break;
		case '#':
			iq = params->hashtag_flag = 1;
			break;
		case '-':
			iq = params->minus_flag = 1;
			break;
		case '0':
			iq = params->zero_flag = 1;
			break;
	}
	return (iq);
}

/**
 * get_modifier - finds the modifier function
 * @s: the string
 * @params: the parameter
 * Return: modifier
 */

int get_modifier(char *s, params_t *params)
{
	int iw = 0;

	switch (*s)
	{
	case 'h':
		iw = params->h_modifier = 1;
		break;
	case 'l':
		iw = params->l_modifier = 1;
		break;
	}
	return (iw);
}

/**
 * get_width - gets the width from the format string
 * @s: the string
 * @params: the parameter
 * @ap: the arg pointer
 * Return: new pointer
 */

char *get_width(char *s, params_t *params, va_list ap)
{
	int id = 0;

	if (*s == '*')
	{
		id = va_arg(ap, int);
		s++;
	}
	else
	{
		while (_isdigit(*s))
			id = id * 10 + (*s++ - '0');
	}
	params->width = id;
	return (s);
}
