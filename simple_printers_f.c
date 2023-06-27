#include "main.h"

/**
 * p_from_to - function  prints a range of char addresses
 * @start: a starting address
 * @stop: a stopping address
 * @except: a except address
 *
 * Return: number bytes to be printed
 */
int p_from_to(char *start, char *stop, char *except)
{
	int ret = 0;

	while (start <= stop)
	{
		if (start != except)
			ret += _putchar(*start);
		start++;
	}
	return (ret);
}

/**
 * p_rev - function prints string in reverse
 * @ap: a string
 * @param: the parameters struct
 *
 * Return: number bytes to be printed
 */
int p_rev(va_list ap, params_type *param)
{
	int len, ret = 0;
	char *str = va_arg(ap, char *);
	(void)param;

	if (str)
	{
		for (len = 0; *str; str++)
			len++;
		str--;
		for (; len > 0; len--, str--)
			ret += _putchar(*str);
	}
	return (ret);
}

/**
 * p_rot13 - function prints string in rot13
 * @ap:a string
 * @param: the parameters struct
 *
 * Return: number bytes to be printed
 */
int p_rot13(va_list ap, params_type *param)
{
	int i, index;
	int count = 0;
	char arr[] =
		"NOPQRSTUVWXYZABCDEFGHIJKLM      nopqrstuvwxyzabcdefghijklm";
	char *a = va_arg(ap, char *);
	(void)param;

	i = 0;
	index = 0;
	while (a[i])
	{
		if ((a[i] >= 'A' && a[i] <= 'Z')
		    || (a[i] >= 'a' && a[i] <= 'z'))
		{
			index = a[i] - 65;
			count += _putchar(arr[index]);
		}
		else
			count += _putchar(a[i]);
		i++;
	}
	return (count);
}


