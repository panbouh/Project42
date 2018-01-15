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

#include <ft_printf.h>

void	conv_mod_j(va_list ap, t_flag_list t_fl, char form)
{
	size_t	i;
	t_flag	keytab[] =
	{
		{'i', &conv_intmaxt},			\
		{'d', &conv_intmaxt},			\
		{'u', &conv_uintmaxt},			\
		{'x', &conv_uintmaxthexa},		\
		{'X', &conv_uintmaxthexaup},	\
		{'o', &conv_uintmaxtocta},		\
		{0, NULL},
	};
	i = 0;

	while (keytab[i].key)
	{
		if (form == keytab[i].key)
		{
			keytab[i].f(ap, t_fl)
			return ;
		}
		i++;
	}
}

void	conv_mod_z(va_list ap, t_flag_list t_fl, char form)
{
	size_t	i;
	t_flag	keytab[] =
	{
		{'i', &sizet},			\
		{'d', &sizet},			\
		{'u', &sizet},			\
		{'x', &sizethexa},		\
		{'X', &sizethexaup},	\
		{'o', &sizetocta},		\
		{0, NULL},
	};
	i = 0;

	while (keytab[i].key)
	{
		if (form == keytab[i].key)
		{
			keytab[i].f(ap, t_fl)
			return ;
		}
		i++;
	}
}