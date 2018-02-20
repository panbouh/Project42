/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_bonus_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccatoire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 11:16:23 by ccatoire          #+#    #+#             */
/*   Updated: 2018/02/20 11:16:25 by ccatoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int		conv_b(va_list ap, t_flag_list t_fl)
{
	unsigned int	nb;
	char			*conv;
	size_t			size;

	nb = va_arg(ap, unsigned int);
	conv = ft_convu_nbase(nb, 2);
	size = 0;
	if (t_fl.put_val || nb)
		size = ft_strlen(conv);
	if (!nb)
		t_fl.sharp = 0;
	calc_wp_num_base(&t_fl, size, (t_fl.sharp * 2));
	if (!t_fl.min)
		ft_putnchar(t_fl.c_width, t_fl.width);
	if (t_fl.sharp && (nb || t_fl.put_val))
		ft_putstr("0b");
	ft_putnchar('0', t_fl.prec);
	if (t_fl.put_val || nb)
		ft_putstr(conv);
	if (t_fl.min)
		ft_putnchar(t_fl.c_width, t_fl.width);
	return (t_fl.field);
}
