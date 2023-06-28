#ifndef _PRINTF_H
#define _PRINTF_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>

#define OUTPUT_BUF_SIZE 1024
#define FLUSH_BUF -1


#define STRING_NULL "(null)"

#define INIT_PARAMS {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}

#define LOWERCASE_CONVERT	1
#define UNSIGNED_CONVERT	2

/**
 * struct parameters - a new struct for parameters
 *
 * @unsign: flag if unsigned value
 *
 * @flag_plus: plus flag specified if exist
 * @flag_space: space flag specified if exist
 * @flag_hashtag: hashtag flag specified if exist
 * @flag_zero: zero flag specified if exist
 * @flag_minus: minus flag specified if exist
 *
 * @width: the wilsth field if exist
 * @precision:  precision field if exist
 *
 * @modifier_h: lenght field specified for h
 * @modifier_l: lenght field specified for l
 *
 */
typedef struct parameters
{
	unsigned int unsign			: 1;

	unsigned int flag_plus		: 1;
	unsigned int flag_space		: 1;
	unsigned int flag_hashtag	: 1;
	unsigned int flag_zero		: 1;
	unsigned int flag_minus		: 1;

	unsigned int width;
	unsigned int precision;

	unsigned int modifier_h		: 1;
	unsigned int modifier_l		: 1;
} params_type;

/**
 * struct specifier - Struct hold a function for specifier
 *
 * @specifier: format token for specifier
 * @f: The function associated with the specifier
 */
typedef struct specifier
{
	char *specifier;
	int (*f)(va_list, params_type *);
} specifier_type;

/* _put.c file */
int _puts(char *str);
int _putchar(int c);

/* p_functions.c file */
int p_char(va_list ap, params_type *param);
int p_int(va_list ap, params_type *param);
int p_string(va_list ap, params_type *param);
int p_percent(va_list ap, params_type *param);
int p_S(va_list ap, params_type *param);

/* number_f.c file */
char *convert(long int num, int base, int flags, params_type *param);
int p_unsigned(va_list ap, params_type *param);
int p_address(va_list ap, params_type *param);

/* specifier_f.c file */
int (*_specifier(char *s))(va_list ap, params_type *param);
int _print_func(char *s, va_list ap, params_type *param);
int _flag(char *s, params_type *param);
int _modifier(char *s, params_type *param);
char *_width(char *s, params_type *param, va_list ap);

/* convert_number_f.c file */
int p_hex(va_list ap, params_type *param);
int p_HEX(va_list ap, params_type *param);
int p_binary(va_list ap, params_type *param);
int p_octal(va_list ap, params_type *param);

/* simple_printers_f.c file */
int p_from_to(char *start, char *stop, char *except);
int p_rev(va_list ap, params_type *param);
int p_rot13(va_list ap, params_type *param);

/* print_number_f.c file */
int _isdigit(int c);
int _strlen(char *s);
int p_number(char *str, params_type *param);
int p_number_right_shift(char *str, params_type *param);
int p_number_left_shift(char *str, params_type *param);

/* params_init.c file */
void params_init(params_type *param, va_list ap);

/* string_fields_f.c file */
char *_precision(char *p, params_type *param, va_list ap);

/* _prinf.c file */
int _printf(const char *format, ...);

#endif


