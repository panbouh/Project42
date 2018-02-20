/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccatoire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 16:58:31 by ccatoire          #+#    #+#             */
/*   Updated: 2018/01/16 16:58:31 by ccatoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ret_err(void)
{
	ft_putendl_fd("<ERROR parsing ERROR>", 2);
	return (FAIL);
}

int	conv_nothing(t_flag_list t_fl, char c)
{
	if (!c)
		return (0);
	if ((t_fl.width -= 1) < 0)
		t_fl.width = 0;
	t_fl.field = t_fl.width + 1;
	if (t_fl.zero && !t_fl.min)
		t_fl.c_width = '0';
	if (!t_fl.min)
		ft_putnchar(t_fl.c_width, t_fl.width);
	ft_putchar(c);
	if (t_fl.min)
		ft_putnchar(t_fl.c_width, t_fl.width);
	return (t_fl.field);
}
