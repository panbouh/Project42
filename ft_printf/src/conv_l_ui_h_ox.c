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
** lu li
*/

void	conv_ulongint(va_list, t_flag_list t_fl)
{
	
}

void	conv_long(va_list ap, t_flag_list t_fl)
{
	long		nb;

	nb = va_arg(ap, int);
	// printf("\n1) w = %i\np = %i\n", t_fl.width, t_fl.prec);
	calc_wp_num(&t_fl, ft_count_digit(ft_abs(nb)));
	// printf("\n2) w = %i\np = %i\n", t_fl.width, t_fl.prec);

	if (nb < 0 && !t_fl.plus)
		t_fl.width--;
	if (!t_fl.min)
		ft_putnchar(t_fl.c_space, t_fl.width);
	if (t_fl.plus && nb >= 0)
		ft_putchar('+');
	if (nb < 0)
		ft_putchar('-');
	ft_putnchar('0', t_fl.prec);
	ft_putnbr(ft_abs(nb));
	if (t_fl.min)
		ft_putnchar(t_fl.c_space, t_fl.width);
}

/*
** ho hxX
*/

void	conv_ushortocta(va_list, t_flag_list t_fl)
{

}

void	conv_ushorthexa(va_list, t_flag_list t_fl)
{

}

void	conv_ushorthexaup(va_list, t_flag_list t_fl)
{

}