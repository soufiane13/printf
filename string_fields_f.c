#include "main.h"

/**
 * _precision - function gets the precision from the format string
 * @p: a format string
 * @param: the parameters struct
 * @ap: an argument pointer
 *
 * Return:  pointer
 */
char *_precision(char *p, params_type *param, va_list ap)
{
	int d = 0;

	if (*p != '.')
		return (p);
	p++;
	if (*p == '*')
	{
		d = va_arg(ap, int);
		p++;
	}
	else
	{
		while (_isdigit(*p))
			d = d * 10 + (*p++ - '0');
	}
	param->precision = d;
	return (p);
}


