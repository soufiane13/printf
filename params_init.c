#include "main.h"

/**
 * params_init - function clears struct fields and reset buf
 * @param: the parameters struct
 * @ap: an argument pointer
 *
 * Return: void
 */
void params_init(params_t *param, va_list ap)
{
	param->unsign = 0;

	param->flag_plus = 0;
	param->flag_space = 0;
	param->flag_hashtag = 0;
	param->flag_zero = 0;
	param->flag_minus = 0;

	param->width = 0;
	param->precision = UINT_MAX;

	param->modifier_h = 0;
	param->modifier_l = 0;
	(void)ap;
}

