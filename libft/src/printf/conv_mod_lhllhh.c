/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccatoire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 16:58:31 by ccatoire          #+#    #+#             */
/*   Updated: 2018/01/16 16:58:31 by ccatoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_conv	g_l_keytab[] =
{
	{'i', &conv_lid},
	{'d', &conv_lid},
	{'s', &conv_ls},
	{'c', &conv_lc},
	{'u', &conv_lu},
	{'x', &conv_lx},
	{'X', &conv_lxm},
	{'o', &conv_lo},
	{'p', &conv_p},
	{'D', &conv_lid},
	{'O', &conv_lo},
	{'U', &conv_lu},
	{'S', &conv_ls},
	{'C', &conv_lc},
	{0, NULL},
};

int	conv_mod_l(va_list ap, t_flag_list t_fl, const char *form, size_t *x)
{
	size_t	i;
	int		ret;

	i = 0;
	ret = 0;
	(*x)++;
	while (form[*x] && !is_conv(form[*x]))
	{
		check_for_pw(form, x, &t_fl, ap);
		*x += check_for_flag(form[*x], &t_fl);
	}
	while (form[*x] && g_l_keytab[i].key)
	{
		if (form[*x] == g_l_keytab[i].key)
		{
			if ((ret = g_l_keytab[i].f(ap, t_fl)) != FAIL)
				return (ret);
		}
		i++;
	}
	return (conv_nothing(t_fl, form[*x]));
}

t_conv	g_ll_keytab[] =
{
	{'i', &conv_llid},
	{'d', &conv_llid},
	{'u', &conv_llu},
	{'x', &conv_llx},
	{'X', &conv_llxm},
	{'o', &conv_llo},
	{'p', &conv_p},
	{'D', &conv_lid},
	{'O', &conv_lo},
	{'U', &conv_lu},
	{'S', &conv_ls},
	{'C', &conv_lc},
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
		check_for_pw(form, x, &t_fl, ap);
		*x += check_for_flag(form[*x], &t_fl);
	}
	while (g_ll_keytab[i].key)
	{
		if (form[*x] == g_ll_keytab[i].key)
		{
			if ((ret = g_ll_keytab[i].f(ap, t_fl)) != FAIL)
				return (ret);
		}
		i++;
	}
	return (conv_nothing(t_fl, form[*x]));
}

t_conv	g_h_keytab[] =
{
	{'i', &conv_hid},
	{'d', &conv_hid},
	{'u', &conv_hu},
	{'x', &conv_hx},
	{'X', &conv_hxm},
	{'o', &conv_ho},
	{'p', &conv_p},
	{'D', &conv_lid},
	{'O', &conv_lo},
	{'U', &conv_lu},
	{'S', &conv_ls},
	{'C', &conv_lc},
	{0, NULL},
};

int	conv_mod_h(va_list ap, t_flag_list t_fl, const char *form, size_t *x)
{
	size_t	i;
	int		ret;

	i = 0;
	ret = 0;
	(*x)++;
	while (!is_conv(form[*x]))
	{
		check_for_pw(form, x, &t_fl, ap);
		*x += check_for_flag(form[*x], &t_fl);
	}
	while (g_h_keytab[i].key)
	{
		if (form[*x] == g_h_keytab[i].key)
		{
			if ((ret = g_h_keytab[i].f(ap, t_fl)) != FAIL)
				return (ret);
		}
		i++;
	}
	return (conv_nothing(t_fl, form[*x]));
}

t_conv	g_hh_keytab[] =
{
	{'i', &conv_hhid},
	{'d', &conv_hhid},
	{'u', &conv_hhu},
	{'x', &conv_hhx},
	{'X', &conv_hhxm},
	{'o', &conv_hho},
	{'p', &conv_p},
	{'D', &conv_lid},
	{'O', &conv_lo},
	{'U', &conv_lu},
	{'S', &conv_ls},
	{'C', &conv_lc},
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
		check_for_pw(form, x, &t_fl, ap);
		*x += check_for_flag(form[*x], &t_fl);
	}
	while (g_hh_keytab[i].key)
	{
		if (form[*x] == g_hh_keytab[i].key)
		{
			if ((ret = g_hh_keytab[i].f(ap, t_fl)) != FAIL)
				return (ret);
		}
		i++;
	}
	return (conv_nothing(t_fl, form[*x]));
}
