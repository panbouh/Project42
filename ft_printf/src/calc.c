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


void		calc_wp_num(t_flag_list *t_fl, long size)
{
	if (t_fl->plus && t_fl->space)
		t_fl->space = 0;

	if (t_fl->prec >= 0)
		if ((t_fl->prec -= size) < 0)
			t_fl->prec = 0;

	if (t_fl->prec >= 0)
		if ((t_fl->width = t_fl->width - t_fl->prec - size) < 0)
			t_fl->width = 0;
}

void		calc_wp_str(t_flag_list *t_fl, int size)
{
	// if (t_fl->zero && !t_fl->min && !t_fl->prec)
	// 	t_fl->c_width = '0';

	if (!t_fl->prec)
		t_fl->prec = size;

	if ((t_fl->width = t_fl->width - t_fl->prec) < 0)
		t_fl->width = 0;
}
