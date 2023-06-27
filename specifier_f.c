#include "main.h"

/**
 * _specifier - fonction finds the format func
 * @s: the format string
 *
 * Return: the number of bytes to be printed
 */
int (*_specifier(char *s))(va_list ap, params_type *param)
{
	specifier_type specifiers[] = {
		{"c", p_char},
		{"d", p_int},
		{"i", p_int},
		{"s", p_string},
		{"%", p_percent},
		{"b", p_binary},
		{"o", p_octal},
		{"u", p_unsigned},
		{"x", p_hex},
		{"X", p_HEX},
		{"p", p_address},
		{"S", p_S},
		{"r", p_rev},
		{"R", p_rot13},
		{NULL, NULL}
	};
	int i = 0;

	while (specifiers[i].specifier)
	{
		if (*s == specifiers[i].specifier[0])
		{
			return (specifiers[i].f);
		}
		i++;
	}
	return (NULL);
}

/**
 * _print_func - finction finds the format func
 * @s: the format string
 * @ap: argument pointer
 * @param: the parameters struct
 *
 * Return: the number of bytes printed
 */
int _print_func(char *s, va_list ap, params_type *param)
{
	int (*f)(va_list, params_type *) = _specifier(s);

	if (f)
		return (f(ap, param));
	return (0);
}

/**
 * _flag - functio finds the flag 
 * @s: the format string
 * @param: the parameters struct
 *
 * Return: if flag was valid
 */
int _flag(char *s, params_type *param)
{
	int i = 0;

	switch (*s)
	{
		case '+':
			i = param->flag_plus = 1;
			break;
		case ' ':
			i = param->flag_space = 1;
			break;
		case '#':
			i = param->flag_hashtag = 1;
			break;
		case '-':
			i = param->flag_minus = 1;
			break;
		case '0':
			i = param->flag_zero = 1;
			break;
	}
	return (i);
}

/**
 * _modifier - function finds the modifier 
 * @s: the format string
 * @param: the parameters struct
 *
 * Return: if modifier was valid
 */
int _modifier(char *s, params_type *param)
{
	int i = 0;

	switch (*s)
	{
	case 'h':
		i = param->modifier_h = 1;
		break;
	case 'l':
		i = param->modifier_l = 1;
		break;
	}
	return (i);
}

/**
 * _width -function gets the width from the format string
 * @s: a format string
 * @param: a parameters struct
 * @ap: an argument pointer
 *
 * Return:  pointer
 */
char *_width(char *s, params_type *param, va_list ap)
{
	int d = 0;

	if (*s == '*')
	{
		d = va_arg(ap, int);
		s++;
	}
	else
	{
		while (_isdigit(*s))
			d = d * 10 + (*s++ - '0');
	}
	param->width = d;
	return (s);
}

