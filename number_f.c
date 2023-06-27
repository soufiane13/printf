#include "main.h"

/**
 * convert - function converter its a clone of itoa
 * @num: number
 * @b: base
 * @flags: argument flags
 * @param: paramater struct
 *
 * Return: string
 */
char *convert(long int num, int b, int flags, params_type *param)
{
	static char *ary;
	static char buff[50];
	char sign = 0;
	char *p;
	unsigned long n = num;
	(void)param;

	if (!(flags & UNSIGNED_CONVERT) && num < 0)
	{
		n = -num;
		sign = '-';

	}
	ary = flags & UNSIGNED_CONVERT ? "0123456789abcdef" : "0123456789ABCDEF";
	p = &buff[49];
	*p = '\0';

	do	{
		*--p = ary[n % base];
		n /= b;
	} while (n != 0);

	if (sign)
		*--p = sign;
	return (p);
}

/**
 * p_unsigned - function prints unsigned integer numbers
 * @ap: an argument pointer
 * @param: the parameters struct
 *
 * Return: bytes printed
 */
int p_unsigned(va_list ap, params_type *param)
{
	unsigned long l;

	if (param->modifier_l)
		l = (unsigned long)va_arg(ap, unsigned long);
	else if (param->modifier_h)
		l = (unsigned short int)va_arg(ap, unsigned int);
	else
		l = (unsigned int)va_arg(ap, unsigned int);
	param->unsign = 1;
	return (print_number(convert(l, 10, UNSIGNED_CONVERT, param), param));
}



/**
 * p_address - function prints address
 * @ap:an argument pointer
 * @param: the parameters struct
 *
 * Return: bytes printed
 */
int p_address(va_list ap, params_type *param)
{
	unsigned long int n = va_arg(ap, unsigned long int);
	char *str;

	if (!n)
		return (_puts("(nil)"));

	str = convert(n, 16, UNSIGNED_CONVERT | LOWERCASE_CONVERT, param);
	*--str = 'x';
	*--str = '0';
	return (p_number(str, param));
}


