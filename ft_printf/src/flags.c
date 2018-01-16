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

void	flag_sharp(t_flag_list *f_list)
{
	f_list->sharp = 1;
}

void	flag_zero(t_flag_list *f_list)
{
	f_list->zero = 1;
}

void	flag_min(t_flag_list *f_list)
{
	f_list->min = 1;
}

void	flag_plus(t_flag_list *f_list)
{
	f_list->plus = 1;
}

void	flag_space(t_flag_list *f_list)
{
	f_list->space = 1;
}