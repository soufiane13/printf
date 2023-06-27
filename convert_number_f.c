#include "main.h"

/**
 * p_hex - function prints unsigned hex numbers in lowercase
 * @ap: an argument pointer
 * @param: the parameters struct
 *
 * Return: bytes to be printed
 */
int p_hex(va_list ap, params_type *param)
{
	unsigned long l;
	int c = 0;
	char *str;

	if (params->modifier_l)
		l = (unsigned long)va_arg(ap, unsigned long);
	else if (params->modifier_h)
		l = (unsigned short int)va_arg(ap, unsigned int);
	else
		l = (unsigned int)va_arg(ap, unsigned int);

	str = convert(l, 16, UNSIGNED_CONVERT | LOWERCASE_CONVERT, param);
	if (param->flag_hashtag && l)
	{
		*--str = 'x';
		*--str = '0';
	}
	param->unsign = 1;
	return (c += p_number(str, param));
}

/**
 * p_HEX - function prints unsigned hex numbers in uppercase
 * @ap: an argument pointer
 * @params: the parameters struct
 *
 * Return: bytes to be printed
 */
int p_HEX(va_list ap, params_type *param)
{
	unsigned long l;
	int c = 0;
	char *str;

	if (param->modifier_l)
		l = (unsigned long)va_arg(ap, unsigned long);
	else if (param->modifier_h)
		l = (unsigned short int)va_arg(ap, unsigned int);
	else
		l = (unsigned int)va_arg(ap, unsigned int);

	str = convert(l, 16, UNSIGNED_CONVERT, param);
	if (param->flag_hashtag && l)
	{
		*--str = 'X';
		*--str = '0';
	}
	param->unsign = 1;
	return (c += p_number(str, param));
}
/**
 * p_binary - function prints unsigned binary number
 * @ap: an argument pointer
 * @param: the parameters struct
 *
 * Return: bytes to be printed
 */
int p_binary(va_list ap, params_type *param)
{
	unsigned int n = va_arg(ap, unsigned int);
	char *str = convert(n, 2, UNSIGNED_CONVERT, param);
	int c = 0;

	if (param->flag_hashtag && n)
		*--str = '0';
	param->unsign = 1;
	return (c += p_number(str, param));
}

/**
 * p_octal - function prints unsigned octal numbers
 * @ap: an argument pointer
 * @param: the parameters struct
 *
 * Return: bytes to be printed
 */
int p_octal(va_list ap, params_type *param)
{
	unsigned long l;
	char *str;
	int c = 0;

	if (param->modifier_l)
		l = (unsigned long)va_arg(ap, unsigned long);
	else if (param->modifier_h)
		l = (unsigned short int)va_arg(ap, unsigned int);
	else
		l = (unsigned int)va_arg(ap, unsigned int);
	str = convert(l, 8, UNSIGNED_CONVERT, param);

	if (param->flag_hashtag && l)
		*--str = '0';
	param->unsign = 1;
	return (c += p_number(str, param));
}

