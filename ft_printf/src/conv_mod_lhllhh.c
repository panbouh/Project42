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

void	conv_mod_l(va_list ap, t_flag_list t_fl, char form)
{
	size_t	i;
	t_conv	keytab[] =
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
	i = 0;

	while (keytab[i].key)
	{
		if (form == keytab[i].key)
		{
			keytab[i].f(ap, t_fl);
			return ;
		}
		i++;
	}
}

void	conv_mod_ll(va_list ap, t_flag_list t_fl, char form)
{
	size_t	i;
	t_conv	keytab[] =
	{
		{'i', &conv_llong},
		{'d', &conv_llong},
		{'u', &conv_ullongint},
		{'x', &conv_ullinthexa},
		{'X', &conv_ullinthexaup},
		{'o', &conv_ullintocta},
		{0, NULL},
	};
	i = 0;

	while (keytab[i].key)
	{
		if (form == keytab[i].key)
		{
			keytab[i].f(ap, t_fl);
			return ;
		}
		i++;
	}
}

void	conv_mod_h(va_list ap, t_flag_list t_fl, char form)
{
	size_t	i;
	t_conv	keytab[] =
	{
		{'i', &conv_short},
		{'d', &conv_short},
		{'u', &conv_ushort},
		{'x', &conv_ushorthexa},
		{'X', &conv_ushorthexaup},
		{'o', &conv_ushortocta},
		{0, NULL},
	};
	i = 0;

	while (keytab[i].key)
	{
		if (form == keytab[i].key)
		{
			keytab[i].f(ap, t_fl);
			return ;
		}
		i++;
	}
}

void	conv_mod_hh(va_list ap, t_flag_list t_fl, char form)
{
	size_t	i;
	t_conv	keytab[] =
	{
		{'i', &conv_schar},
		{'d', &conv_schar},
		{'u', &conv_uchar},
		{'x', &conv_ucharhexa},
		{'X', &conv_ucharhexaup},
		{'o', &conv_ucharocta},
		{0, NULL},
	};
	i = 0;

	while (keytab[i].key)
	{
		if (form == keytab[i].key)
		{
			keytab[i].f(ap, t_fl);
			return ;
		}
		i++;
	}
}