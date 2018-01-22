/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccatoire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 14:58:15 by ccatoire          #+#    #+#             */
/*   Updated: 2017/11/16 14:58:15 by ccatoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_conv	g_j_keytab[] =
{
	{'i', &conv_intmaxt},
	{'d', &conv_intmaxt},
	{'u', &conv_uintmaxt},
	{'x', &conv_uintmaxthexa},
	{'X', &conv_uintmaxthexaup},
	{'o', &conv_uintmaxtocta},
	{0, NULL},
};

int		conv_mod_j(va_list ap, t_flag_list t_fl, char form)
{
	size_t	i;
	int		ret;

	i = 0;
	ret = 0;
	while (g_j_keytab[i].key)
	{
		if (form == g_j_keytab[i].key)
		{
			if ((ret = g_j_keytab[i].f(ap, t_fl)))
				return (ret);
		}
		i++;
	}
	return (conv_nothing(t_fl, form));
}

t_conv	g_z_keytab[] = {
	{'i', &conv_sizet},
	{'d', &conv_sizet},
	{'u', &conv_sizet},
	{'x', &conv_sizethexa},
	{'X', &conv_sizethexaup},
	{'o', &conv_sizetocta},
	{0, NULL},
};

int		conv_mod_z(va_list ap, t_flag_list t_fl, char form)
{
	size_t	i;
	int		ret;

	i = 0;
	ret = 0;
	while (g_z_keytab[i].key)
	{
		if (form == g_z_keytab[i].key)
		{
			if ((ret = g_z_keytab[i].f(ap, t_fl)))
				return (ret);
		}
		i++;
	}
	return (conv_nothing(t_fl, form));
}