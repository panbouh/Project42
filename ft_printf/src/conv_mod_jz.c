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

void	conv_mod_j(va_list ap, t_flag_list t_fl, char form)
{
	t_conv	keytab[] = {
		{'i', &conv_intmaxt},
		{'d', &conv_intmaxt},
		{'u', &conv_uintmaxt},
		{'x', &conv_uintmaxthexa},
		{'X', &conv_uintmaxthexaup},
		{'o', &conv_uintmaxtocta},
		{0, NULL},
	};
	size_t	i;

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

void	conv_mod_z(va_list ap, t_flag_list t_fl, char form)
{
	t_conv	keytab[] = {
		{'i', &conv_sizet},
		{'d', &conv_sizet},
		{'u', &conv_sizet},
		{'x', &conv_sizethexa},
		{'X', &conv_sizethexaup},
		{'o', &conv_sizetocta},
		{0, NULL},
	};
	size_t	i;

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
