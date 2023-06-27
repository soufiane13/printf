#include "main.h"

/**
 * _printf - function that produces output according to a format.
 * @format: the format string printed in the end after processed
 *
 * Return: number of bytes printed
 */
int _printf(const char *format, ...)
{
	int ret = 0;
	va_list ap;
	char *p, *start;
	params_type param = INIT_PARAMS;

	va_start(ap, format);

	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (p = (char *)format; *p; p++)
	{
		params_init(&param, ap);
		if (*p != '%')
		{
			ret += _putchar(*p);
			continue;
		}
		start = p;
		p++;
		while (_flag(p, &param))
		{
			p++;
		}
		p = _width(p, &param, ap);
		p = _precision(p, &param, ap);
		if (_modifier(p, &param))
			p++;
		if (!_specifier(p))
			ret += p_from_to(start, p,
				param.l_modifier || param.h_modifier ? p - 1 : 0);
		else
			ret += _print_func(p, ap, &param);
	}
	_putchar(FLUSH_BUF);
	va_end(ap);
	return (ret);
}


