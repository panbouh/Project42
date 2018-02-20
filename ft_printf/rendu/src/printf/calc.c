#include "ft_printf.h"

void		calc_wp_num(t_flag_list *t_fl, long size, int is_sign)
{
	char	sign;

	sign = 0;
	if (is_sign)
	{
		if (t_fl->neg)
			t_fl->c_sign = '-';
		else if (t_fl->space && !t_fl->plus)
			t_fl->c_sign = ' ';
		else
			t_fl->c_sign = '+';
	}
	if (t_fl->zero && !t_fl->min && !t_fl->prec && t_fl->put_val)
		t_fl->c_width = '0';
	if ((t_fl->prec -= size) < 0)
		t_fl->prec = 0;
	if (is_sign && (t_fl->plus || t_fl->space || t_fl->neg))
		{
			t_fl->width--;
			sign = 1;
		}
	if ((t_fl->width -= (t_fl->prec + size)) < 0)
		t_fl->width = 0;
	t_fl->field = t_fl->width + t_fl->prec + size + sign;
}

void		calc_wp_str(t_flag_list *t_fl, int size)
{
	if (t_fl->zero && !t_fl->min)
		t_fl->c_width = '0';
	if (!t_fl->put_val)
		size = 0;
	if (!t_fl->prec || t_fl->prec > size)
		t_fl->prec = size;
	if ((t_fl->width -= t_fl->prec) < 0)
		t_fl->width = 0;
	t_fl->field = t_fl->width + t_fl->prec;
}

void		calc_wp_num_base(t_flag_list *t_fl, long size, int sharp)
{
	if (t_fl->zero && !t_fl->min && !t_fl->prec && t_fl->put_val)
		t_fl->c_width = '0';
	if ((t_fl->prec -= size) < 0)
		t_fl->prec = 0;
	if ((t_fl->width -= (t_fl->prec + size + sharp)) < 0)
		t_fl->width = 0;
	t_fl->field = t_fl->width + t_fl->prec + size + sharp;
	if (t_fl->zero && !t_fl->min && t_fl->put_val)
	{
		t_fl->prec += t_fl->width;
		t_fl->width = 0;
	}
}
