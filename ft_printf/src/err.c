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

int	ret_err()
{
	ft_putendl_fd("<ERROR parsing ERROR>", 2);
	return (FAIL);
}

int	conv_nothing(t_flag_list t_fl, char c)
{
	char	c_space;

	t_fl.prec = 0;
	calc_wp_str(&t_fl, 1);

	if (!t_fl.min)
		ft_putnchar(t_fl.c_space, t_fl.width);

	ft_putchar(c);

	if (t_fl.min)
		ft_putnchar(t_fl.c_space, t_fl.width);
	return (OK);
}