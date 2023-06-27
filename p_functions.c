#include "main.h"

/**
 * p_char - function prints character
 * @ap: an argument pointer
 * @param: the parameters struct
 *
 * Return: number chars printed
 */
int p_char(va_list ap, params_type *param)
{
	char pd_char = ' ';
	unsigned int pd = 1, ret = 0, cha = va_arg(ap, int);

	if (param->flag_minus)
		ret += _putchar(cha);
	while (pd++ < param->width)
		ret += _putchar(pd_char);
	if (!param->flag_minus)
		ret += _putchar(cha);
	return (ret);
}

/**
 * p_int - function prints integer
 * @ap: an argument pointer
 * @param: the parameters struct
 *
 * Return: number chars to be printed
 */
int p_int(va_list ap, params_type *param)
{
	long l;

	if (param->modifier_l)
		l = va_arg(ap, long);
	else if (param->modifier_h)
		l = (short int)va_arg(ap, int);
	else
		l = (int)va_arg(ap, int);
	return (p_number(convert(l, 10, 0, param), param));
}

/**
 * p_string - function prints string
 * @ap: an argument pointer
 * @param: the parameters struct
 *
 * Return: number chars to be printed
 */
int p_string(va_list ap, params_type *param)
{
	char *str = va_arg(ap, char *), pd_char = ' ';
	unsigned int pd = 0, ret = 0, i = 0, j;

	(void)param;
	switch ((int)(!str))
		case 1:
			str = STRING_NULL;

	j = pd = _strlen(str);
	if (param->precision < pd)
		j = pd = param->precision;

	if (param->flag_minus)
	{
		if (param->precision != UINT_MAX)
			for (i = 0; i < pd; i++)
				ret += _putchar(*str++);
		else
			ret += _puts(str);
	}
	while (j++ < param->width)
		ret += _putchar(pad_char);
	if (!param->flag_minus)
	{
		if (param->precision != UINT_MAX)
			for (i = 0; i < pd; i++)
				ret += _putchar(*str++);
		else
			ret += _puts(str);
	}
	return (ret);
}

/**
 * p_percent - function prints string
 * @ap: an argument pointer
 * @param: the parameters struct
 *
 * Return: number chars to be printed
 */
int p_percent(va_list ap, params_type *param)
{
	(void)ap;
	(void)param;
	return (_putchar('%'));
}

/**
 * p_S - fuction for custom format specifier
 * @ap: an argument pointer
 * @param: the parameters struct
 *
 * Return: number chars to be printed
 */
int p_S(va_list ap, params_type *param)
{
	char *str = va_arg(ap, char *);
	char *hexa;
	int ret = 0;

	if ((int)(!str))
		return (_puts(STRING_NULL));
	for (; *str; str++)
	{
		if ((*str > 0 && *str < 32) || *str >= 127)
		{
			ret += _putchar('\\');
			ret += _putchar('x');
			hexa = convert(*str, 16, 0, param);
			if (!hexa[1])
				ret += _putchar('0');
			ret += _puts(hexa);
		}
		else
		{
			ret += _putchar(*str);
		}
	}
	return (ret);
}

