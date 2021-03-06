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

t_conv	g_j_keytab[] =
{
	{'i', &conv_jid},
	{'d', &conv_jid},
	{'u', &conv_ju},
	{'x', &conv_jx},
	{'X', &conv_jxm},
	{'o', &conv_jo},
	{'p', &conv_p},
	{'D', &conv_lid},
	{'O', &conv_lo},
	{'U', &conv_lu},
	{'S', &conv_ls},
	{'C', &conv_lc},
	{0, NULL},
};

int		conv_mod_j(va_list ap, t_flag_list t_fl, const char *form, size_t *x)
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
	while (g_j_keytab[i].key)
	{
		if (form[*x] == g_j_keytab[i].key)
		{
			if ((ret = g_j_keytab[i].f(ap, t_fl)) != FAIL)
				return (ret);
		}
		i++;
	}
	return (conv_nothing(t_fl, form[*x]));
}

t_conv	g_z_keytab[] = {
	{'i', &conv_zid},
	{'d', &conv_zid},
	{'u', &conv_zu},
	{'x', &conv_zx},
	{'X', &conv_zxm},
	{'o', &conv_zo},
	{'p', &conv_p},
	{'D', &conv_lid},
	{'O', &conv_lo},
	{'U', &conv_lu},
	{'S', &conv_ls},
	{'C', &conv_lc},
	{0, NULL},
};

int		conv_mod_z(va_list ap, t_flag_list t_fl, const char *form, size_t *x)
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
	while (g_z_keytab[i].key)
	{
		if (form[*x] == g_z_keytab[i].key)
		{
			if ((ret = g_z_keytab[i].f(ap, t_fl)) != FAIL)
				return (ret);
		}
		i++;
	}
	return (conv_nothing(t_fl, form[*x]));
}
