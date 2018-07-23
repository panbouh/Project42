/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_pw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccatoire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 18:26:11 by ccatoire          #+#    #+#             */
/*   Updated: 2018/05/20 18:26:11 by ccatoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_w(const char *form, size_t *i, t_flag_list *t_fl, va_list ap)
{
	if ((ft_isdigit(form[*i]) && form[*i] != '0') || form[*i] == '*')
	{
		if (form[*i] == '*')
		{
			t_fl->width = va_arg(ap, int);
			(*i)++;
		}
		else
		{
			t_fl->width = ft_atoi(&form[*i]);
			*i += ft_count_digit(t_fl->width);
		}
	}
}

void	check_p(const char *form, size_t *i, t_flag_list *t_fl, va_list ap)
{
	size_t	size;

	size = 1;
	if (form[*i] == '.')
	{
		if (form[*i + 1] == '*')
			t_fl->prec = va_arg(ap, int);
		else
			t_fl->prec = ft_atoi(&form[*i + 1]);
		if (t_fl->prec == 0)
		{
			t_fl->put_val = 0;
			if (form[*i + 1] == '0')
				size++;
		}
		else
			size += ft_count_digit(t_fl->prec);
		*i += size;
	}
}

void	check_for_pw(const char *form, size_t *i, t_flag_list *t_fl, va_list ap)
{
	check_w(form, i, t_fl, ap);
	check_p(form, i, t_fl, ap);
}
