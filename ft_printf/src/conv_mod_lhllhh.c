/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_conv_chiante.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccatoire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 16:04:22 by ccatoire          #+#    #+#             */
/*   Updated: 2018/01/15 16:04:23 by ccatoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_conv	g_l_keytab[] =
{
	{'i', &conv_long},
	{'d', &conv_long},
	{'s', &conv_wchat},
	{'c', &conv_wintt},
	{'u', &conv_ulongint},
	{'x', &conv_ulinthexa},
	{'X', &conv_ulinthexaup},
	{'o', &conv_ulintocta},
	{0, NULL},
};

int	conv_mod_l(va_list ap, t_flag_list t_fl, const char *form, size_t *x)
{
	size_t	i;
	int		ret;

	i = 0;
	ret = 0;

	// printf("avant : c = %c\n", form[*x]);
	(*x)++;
	while (!is_conv(form[*x]))
	{
		check_for_pw(form, x, &t_fl);
		*x += check_for_flag(form[*x], &t_fl);
	}
	// printf("apres : c = %c\n", form[*x]);
	while (g_l_keytab[i].key)
	{
		if (form[*x] == g_l_keytab[i].key)
		{
			if ((ret = g_l_keytab[i].f(ap, t_fl)))
				return (ret);
		}
		i++;
	}
	return (conv_nothing(t_fl, form[*x]));
}

t_conv	g_ll_keytab[] =
{
	{'i', &conv_llong},
	{'d', &conv_llong},
	{'u', &conv_ullongint},
	{'x', &conv_ullinthexa},
	{'X', &conv_ullinthexaup},
	{'o', &conv_ullintocta},
	{0, NULL},
};

int	conv_mod_ll(va_list ap, t_flag_list t_fl, const char *form, size_t *x)
{
	size_t	i;
	int		ret;

	i = 0;
	ret = 0;

	*x += 2;
	while (!is_conv(form[*x]))
	{
		check_for_pw(form, x, &t_fl);
		*x += check_for_flag(form[*x], &t_fl);
	}
	// printf("apres : c = %c\n", form[*x]);
	while (g_ll_keytab[i].key)
	{
		if (form[*x] == g_ll_keytab[i].key)
		{
			if ((ret = g_ll_keytab[i].f(ap, t_fl)))
				return (ret);
		}
		i++;
	}
	return (conv_nothing(t_fl, form[*x]));
}

t_conv	g_h_keytab[] =
{
	{'i', &conv_short},
	{'d', &conv_short},
	{'u', &conv_ushort},
	{'x', &conv_ushorthexa},
	{'X', &conv_ushorthexaup},
	{'o', &conv_ushortocta},
	{0, NULL},
};

int	conv_mod_h(va_list ap, t_flag_list t_fl, const char *form, size_t *x)
{
	size_t	i;
	int		ret;

	i = 0;
	ret = 0;

	// printf("avant : c = %c\n", form[*x]);
	(*x)++;
	while (!is_conv(form[*x]))
	{
		check_for_pw(form, x, &t_fl);
		*x += check_for_flag(form[*x], &t_fl);
	}
	// printf("apres : c = %c\n", form[*x]);
	while (g_h_keytab[i].key)
	{
		if (form[*x] == g_h_keytab[i].key)
		{
			if ((ret = g_h_keytab[i].f(ap, t_fl)))
				return (ret);
		}
		i++;
	}
	return (conv_nothing(t_fl, form[*x]));}

t_conv	g_hh_keytab[] =
{
	{'i', &conv_schar},
	{'d', &conv_schar},
	{'u', &conv_uchar},
	{'x', &conv_ucharhexa},
	{'X', &conv_ucharhexaup},
	{'o', &conv_ucharocta},
	{0, NULL},
};

int	conv_mod_hh(va_list ap, t_flag_list t_fl, const char *form, size_t *x)
{
	size_t	i;
	int		ret;

	i = 0;
	ret = 0;

	*x += 2;
	while (!is_conv(form[*x]))
	{
		check_for_pw(form, x, &t_fl);
		*x += check_for_flag(form[*x], &t_fl);
	}
	// printf("apres : c = %c\n", form[*x]);
	while (g_hh_keytab[i].key)
	{
		if (form[*x] == g_hh_keytab[i].key)
		{
			if ((ret = g_hh_keytab[i].f(ap, t_fl)))
				return (ret);
		}
		i++;
	}
	return (conv_nothing(t_fl, form[*x]));
}
