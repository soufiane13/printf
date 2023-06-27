#include "main.h"

/**
 * _isdigit - function  checks if character is digit
 * @c: the character to check
 *
 * Return: 1 if digit or  0 .
 */
int _isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

/**
 * _strlen - fuctio returns the length of a string
 * @s: the string  length to check
 *
 * Return: a integer length of string
 */
int _strlen(char *s)
{
	int i = 0;

	while (*s++)
		i++;
	return (i);
}

/**
 * p_number - function  prints a number with options
 * @str: the base number as a string
 * @param: the parameter struct
 *
 * Return: chars to be printed
 */
int p_number(char *str, params_type *param)
{
	unsigned int i = _strlen(str);
	int neg = (!param->unsign && *str == '-');

	if (!param->precision && *str == '0' && !str[1])
		str = "";
	if (neg)
	{
		str++;
		i--;
	}
	if (param->precision != UINT_MAX)
		while (i++ < param->precision)
			*--str = '0';
	if (neg)
		*--str = '-';

	if (!param->flag_minus)
		return (p_number_right_shift(str, param));
	else
		return (p_number_left_shift(str, param));
}

/**
 * p_number_right_shift - function prints a number with options
 * @str: the base number as a string
 * @param: the parameter struct
 *
 * Return: chars to be printed
 */
int p_number_right_shift(char *str, params_type *param)
{
	unsigned int n = 0, neg, neg2, i = _strlen(str);
	char pd_char = ' ';

	if (param->zero_flag && !param->flag_minus)
		pd_char = '0';
	neg = neg2 = (!param->unsign && *str == '-');
	if (neg && i < param->width && pd_char == '0' && !param->flag_minus)
		str++;
	else
		neg = 0;
	if ((param->flag_plus && !neg2) ||
		(!param->flag_plus && param->flag_space && !neg2))
		i++;
	if (neg && pd_char == '0')
		n += _putchar('-');
	if (param->flag_plus && !neg2 && pd_char == '0' && !param->unsign)
		n += _putchar('+');
	else if (!param->flag_plus && param->flag_space && !neg2 &&
		!param->unsign && param->flag_zero)
		n += _putchar(' ');
	while (i++ < params->width)
		n += _putchar(pd_char);
	if (neg && pd_char == ' ')
		n += _putchar('-');
	if (param->flag_plus && !neg2 && pd_char == ' ' && !param->unsign)
		n += _putchar('+');
	else if (!param->flag_plus && param->flag_space && !neg2 &&
		!param->unsign && !param->flag_zero)
		n += _putchar(' ');
	n += _puts(str);
	return (n);
}

/**
 * p_number_left_shift - function prints a number with options
 * @str: a base number as a string
 * @param: the parameter struct
 *
 * Return: chars printed
 */
int p_number_left_shift(char *str, params_type *param)
{
	unsigned int n = 0, neg, neg2, i = _strlen(str);
	char pd_char = ' ';

	if (param->flag_zero && !param->flag_minus)
		pd_char = '0';
	neg = neg2 = (!param->unsign && *str == '-');
	if (neg && i < param->width && pd_char == '0' && !param->flag_minus)
		str++;
	else
		neg = 0;

	if (param->flag_plus && !neg2 && !param->unsign)
		n += _putchar('+'), i++;
	else if (param->flag_space && !neg2 && !param->unsign)
		n += _putchar(' '), i++;
	n += _puts(str);
	while (i++ < param->width)
		n += _putchar(pd_char);
	return (n);
}

