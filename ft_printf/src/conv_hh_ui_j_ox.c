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

/*
** hhu hhi/d
*/

int	conv_schar(va_list ap, t_flag_list t_fl)
{
	ft_putstr("test hhu");
	return (1);
}

int	conv_uchar(va_list ap, t_flag_list t_fl)
{
	ft_putstr("test hhi");
	return (1);
}

/*
** jo jx jX
*/

int	conv_uintmaxtocta(va_list ap, t_flag_list t_fl)
{
	ft_putstr("test jo");
	return (1);
}

int	conv_uintmaxthexa(va_list ap, t_flag_list t_fl)
{
	ft_putstr("test jx");
	return (1);
}

int	conv_uintmaxthexaup(va_list ap, t_flag_list t_fl)
{
	ft_putstr("test jX");
	return (1);
}