#include "main.h"

/**
 * _printf - print anything
 * @format: the string
 * Return: number
 */
int _printf(const char *format, ...)
{
	int sm = 0;
	va_list ap;
	char *po, *start;
	params_t params = PARAMS_INIT;

	va_start(ap, format);

	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (po = (char *)format; *po; po++)
	{
		init_params(&params, ap);
		if (*po != '%')
		{
			sm += _putchar(*po);
			continue;
		}
		start = po;
		po++;
		while (get_flag(po, &params))
		{
			po++;
		}
		po = get_width(po, &params, ap);
		po = get_precision(po, &params, ap);
		if (get_modifier(po, &params))
			po++;
		if (!get_specifier(po))
			sm += print_from_to(start, po,
				params.l_modifier || params.h_modifier ? po - 1 : 0);
		else
			sm += get_print_func(po, ap, &params);
	}
	_putchar(BUF_FLUSH);
	va_end(ap);
	return (sm);
}
