#include "main.h"

/**
 * get_precision - get the precision from the format string
 * @p: the string
 * @params: the parameter
 * @ap: the arg pointer
 * Return: pointer
 */

char *get_precision(char *p, params_t *params, va_list ap)
{
	int id = 0;

	if (*p != '.')
		return (p);
	p++;
	if (*p == '*')
	{
		id = va_arg(ap, int);
		p++;
	}
	else
	{
		while (_isdigit(*p))
			id = id * 10 + (*p++ - '0');
	}
	params->precision = id;
	return (p);
}
