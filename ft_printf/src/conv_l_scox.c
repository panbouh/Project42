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

/*
**  ls lc lo lx lX
*/

int	conv_wchat(va_list ap, t_flag_list t_fl)
{
	ft_putstr("test ls");
	return (1);
}

int	conv_wintt(va_list ap, t_flag_list t_fl)
{
	ft_putstr("test lc");
	return (1);
}

int	conv_ulintocta(va_list ap, t_flag_list t_fl)
{
	ft_putstr("test lo");
	return (1);
}


int	conv_ulinthexa(va_list ap, t_flag_list t_fl)
{
	ft_putstr("test lx");
	return (1);
}


int	conv_ulinthexaup(va_list ap, t_flag_list t_fl)
{
	ft_putstr("test lX");
	return (1);
}