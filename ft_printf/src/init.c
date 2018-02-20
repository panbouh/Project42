/* ************************************************************************** */
/*                                                         */
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

t_flag_list	init_fl()
{
	t_flag_list	new;

	new.sharp = 0;
	new.zero = 0;
	new.min = 0;
	new.plus = 0;
	new.space = 0;
	new.neg = 0;
	new.put_val = 1;
	new.width = 0;
	new.field = 0;
	new.prec = 0;
	new.c_width = ' ';
	new.c_sign = 0;
	return (new);
}

t_index		init_id()
{
	t_index	new;

	new.i = 0;
	new.ret = 0;
	new.ret_end = 0;
	new.count = 0;
	return (new);
}
