#ifndef _PRINTF_H
#define _PRINTF_H

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
 * @width: the width field if exist
 * @precision:  precision field if exist
 *
 * @modifier_h: length field specified for h
 * @modifier_l: length field specified for l
 *
 */

/* _prinf.c file */
int _printf(const char *format, ...);

#endif
