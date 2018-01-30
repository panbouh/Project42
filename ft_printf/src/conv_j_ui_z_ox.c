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
** ju ji/d
*/

int	conv_uintmaxt(va_list ap, t_flag_list t_fl)
{
	ft_putstr("test ju");
	return (1);
}

int	conv_intmaxt(va_list ap, t_flag_list t_fl)
{
	ft_putstr("test ji/d");
	return (1);
}

/*
** zo zx zX
*/

int	conv_sizethexa(va_list ap, t_flag_list t_fl)
{
	ft_putstr("test zo");
	return (1);
}

int	conv_sizethexaup(va_list ap, t_flag_list t_fl)
{
	ft_putstr("test zx");
	return (1);
}

int	conv_sizetocta(va_list ap, t_flag_list t_fl)
{
	ft_putstr("test zX");
	return (1);
}